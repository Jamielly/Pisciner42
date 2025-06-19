/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:38:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/06/16 10:08:32 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef NULP
	#define NULP ((void *)0)
#endif

struct s_dict{
	char			*num;
	char			*text;
	int				start_zeros; //unidade 0, dezena 1, centena 2
	int				end_zeros;	//a partir do mil, a cada 3 caracteres.
	struct s_dict	*s_next;	//experimental
};

int				is_alpha(char *str);
int				is_numeric(char *str);
char			*get_text();
char			*get_number();

struct s_dict	*fill_dict(char *stream);
void			fill_dict_item(struct s_dict *dict, char *line);
//file operations
int				is_dict_line_valid(char *line);
int				count_line(char *stream);
int				check_file_size(char *filename);
char			*file_to_string(char *filename, int total_bytes);

void			ft_putstr();
int				ft_strlen(char *str);
int				ft_is_num_string(char *str);
void			ft_putnbr(int nb);
char			*get_line(char *str, int line_number);
char			*ft_strstr(char *str, char *to_find);
char			*extract_number(char *line);
char			*extract_num_in_words(char *line);
int				ft_strcmp(char *s1, char *s2);
int				count_zeros(char *s);

int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		int	size;
		char *stream;
		struct s_dict *dict;
		
		size = check_file_size("numbers.dict");
		if (size > 0)
		{
			stream = file_to_string("numbers.dict", size);

			dict = fill_dict(stream);
			ft_putstr(dict[2].text);
			free(stream);
		}
	}
	else
		ft_putstr(argv[0]);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	check_file_size(char *filename)
{
	int	byte_read;
	char	c[16];
	int	size;
	int	fd;

	size = -1;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		size = read(fd, &c, 16);
		byte_read = size;
		while(byte_read >= 16)
		{
			byte_read = read(fd, &c, 16);
			size += byte_read;
		}
		close(fd);
	}
	return (size);
}

char	*file_to_string(char *filename, int total_bytes)
{
	int	fd;
	char	*stream;

	fd = open(filename, O_RDONLY);
	if (fd != -1 && total_bytes > 0)
	{
		stream = malloc(total_bytes * sizeof(char));
		read(fd, stream, total_bytes);
		return (stream);
	}
	return (NULP);
}
//Precisa ter <string><0 a n espacos>:<0 a n espacos><string>\0
int	is_dict_line_valid(char *line)
{
	char	*colon;
	int		ncolon;
	int		len;
	
	ncolon = 0;
	colon = ft_strstr(line, ":");
	while (colon != NULP && ncolon < 2)
	{
		colon++;
		ncolon++;
		colon = ft_strstr(colon, ":");
		if (colon == NULP)
			break;
	}
	if (ncolon != 1)
		return (0);
	if (!ft_is_num_string(line))
		return (0);
	colon = ft_strstr(line, ":");
	if (!ft_strcmp(++colon, " \n"))
		return (0);
	len = ft_strlen(line);
	if (line[len - 1] != '\n')
		return (0);
	if (!is_alpha(colon))
		return (0);
	return (1);
}

int	is_numeric(char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb <= 9)
	{
		n = nb + '0';
		write(1, &n, 1);
	}
}

char	*get_line(char *str, int line_number)
{
	char *line;
	int i;

	i = 0;
	if (*str == '\0')
		return (NULP);
	if (line_number <= 0)
	{
		while (str[i] && str[i] != '\n')
			i++;
		i++;
		line = malloc(i * sizeof(char));
		line[i] = '\0';
		while(--i >= 0)
			line[i] = str[i];
		return (line);
	}
	while (*str && *str != '\n')
		str++;
	str++;
	return (get_line(str, line_number - 1));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i_str;
	int	i_to_find;
	int	found;

	if (!str)
		return (NULP);
	if (ft_strlen(to_find) == 0)
		return (str);
	i_str = -1;
	while (++i_str < ft_strlen(str))
	{
		i_to_find = -1;
		found = 1;
		while (to_find[++i_to_find])
		{
			if (str[i_to_find + i_str] != to_find[i_to_find])
			{
				found = 0;
				break ;
			}
		}
		if (found)
			return (str + i_str);
	}
	return (NULP);
}

int	ft_is_num_string(char *str)
{
	while (*str && *str != ' ' && *str != ':')
	{
		if (!is_numeric(str))
			return (0);
		str++;
	}
	if (*str == ':')
		return (1);
	while (*str != ':')
	{
		if(*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	is_alpha(char *str)
{git@vogsphere-v2.42sp.org.br:vogsphere/intra-uuid-bfbd07d8-bd81-49a3-a46b-d644f7d3ea89-6615034-jasilva-
	line = get_line(stream, i);
	while (line != NULP)
	{	
		free(line);
		i++;
		line = get_line(stream, i);
	}
	return (i);
}

char	*extract_num_in_words(char *line)
{
	char	*text;
	int		pos_spaces;
	int		pos;

	pos_spaces = 0;
	pos = 0;
	while (line[pos_spaces] && line[pos_spaces] == ' ')
		pos_spaces++;
	while (line[pos_spaces] && line[pos_spaces] != '\n')
	{
		pos++;
		pos_spaces++;
	}
	text = malloc(pos * sizeof(char));
	if (!text)
		return (NULP);
	text[pos] = '\0';
	pos_spaces--;
	while (--pos >= 0)
	{
		text[pos] = line[pos_spaces];
		pos_spaces--;
	}
	return (text);
}

char	*extract_number(char *line)
{
	char	*num;
	int		pos;

	pos = 0;
	while (line[pos] != ' ' && line[pos] != ':')
		pos++;
	num = malloc(pos * sizeof(char));
	if (!num)
		return (NULP);
	num[pos] = '\0';
	while(--pos >= 0)
		num[pos] = line[pos];
	return (num);
}

void	fill_dict_item(struct s_dict *dict, char *line)
{
	char	*colon;
	int		zeros;

	dict->num = extract_number(line);
	colon = ft_strstr(line, ":");
	colon++;
	dict->text = extract_num_in_words(colon);
	zeros = count_zeros(dict->num);
	if (zeros >= 3)
	{
		dict->start_zeros = zeros;
		dict->end_zeros = zeros + 2;
	}
	else
	{
		dict->start_zeros = 0;
		dict->end_zeros = 0;
	}
}

int	count_zeros(char *s)
{
	int zeros;
	
	zeros = 0;
	while(*s)
	{
		if (*s == '0')
			zeros++;
		s++;
	}
	return (zeros);
}

struct s_dict	*fill_dict(char *stream)
{
	int				i;
	int				total_lines;
	char			*line;
	struct s_dict	*dict;

	total_lines = count_line(stream);
	total_lines--;
	if (total_lines != 0)
		dict = malloc(total_lines * sizeof(struct s_dict));
	else
		return (NULP);
	i = 0;
	line = get_line(stream, i);
	while (i < total_lines)
	{
		if(line != NULP && is_dict_line_valid(line))
		{
			fill_dict_item(&dict[i], line);
			//free(line);
			if (i > 0)
				dict[i-1].s_next = &dict[i];
		}
		i++;
		line = get_line(stream, i);
	}
	return (dict);
}
//1 tratar o argv
//	1.1 Abrir e ler o arquivo .dict
//	1.2 Ignorar linhas vazias ou mal formatada
//	1.3 Separar chave numerica e valor textual
//	1.4 Permitir consulta eficiente por chave (string)
//	1.5 Tratar erros de parsing
//	1.5 Falta de ':' na linha
//	1.6 valores ausentes ou inválidos
//	1.7 Liberar corrretamente toda memória utilizada
//2 Conversao para texto
//	2.1 Validar se o numero é positivo (usar mesmo algoritmo de atoi)
//	2.2 Dividir o numero em grupos de 3 digitos, da direita
// para a esquerda (ex: unidades, milhares, milhões)
//	2.3 Para cada grupo identificar centenas, dezenas e unidades.
//	2.4 Montar
//unidade 0, dezena 1, centena 2