/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:21:07 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 22:21:09 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "utils.h"
#include <stdlib.h>

int	print_hundreds(char *digits, t_dict *dict, int *first);
int	print_tens(char *digits, t_dict *dict, int *first);
int	print_scale(int scale, t_dict *dict, int *first);
int	ft_strlen(char *str);

int	is_zero_triplet(char *triplet)
{
	return (triplet[0] == '0' && triplet[1] == '0' && triplet[2] == '0');
}

char	*add_leading_zeros(char *src, int len)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc(4);
	if (!dst)
		return (0);
	i = 0;
	while (i < 3 - len)
		dst[i++] = '0';
	j = 0;
	while (i < 3)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}

int	print_triplet(char *triplet, t_dict *dict, int *first, int scale)
{
	if (!is_zero_triplet(triplet))
	{
		if (!print_hundreds(triplet, dict, first))
			return (0);
		if (!print_tens(&triplet[1], dict, first))
			return (0);
		if (!print_scale(scale, dict, first))
			return (0);
	}
	return (1);
}

int	print_number(char *num, t_dict *dict)
{
	int		len;
	int		scale;
	int		first;
	char	*triplet;
	int		rem;

	len = ft_strlen(num);
	if (len == 1 && num[0] == '0')
		return (ft_putstr(get_value("0", dict)), 1);
	scale = 0;
	first = 1;
	while (len > 0)
	{
		rem = len % 3;
		if (rem == 0)
			rem = 3;
		num[len] = '\0';
		triplet = add_leading_zeros(&num[len - rem], rem);
		if (!print_triplet(triplet, dict, &first, scale))
			return (free(triplet), 0);
		free(triplet);
		len -= rem;
		scale++;
	}
	ft_putchar('\n');
	return (1);
}
