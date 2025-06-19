/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:49:23 by klima-do          #+#    #+#             */
/*   Updated: 2025/06/08 17:29:53 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putmatrix(char *data, int size);
void	initialize_array(char *arr, int size);
int		is_distinct_in_col(int size, char *data, int index);
int		is_distinct_in_row(int size, char *data, int index);
int		is_top_visibility_valid(int size, char *data, int v_t, int index);
int		is_bottom_visibility_valid(int size, char *data, int v_b, int index);
int		is_left_visibility_valid(int size, char *data, int v_l, int index);
int		is_right_visibility_valid(int size, char *data, int v_r, int index);
int		parser(char *str);
int		ft_strlen(char *str);

void	check(char *data, int *vars, int size, char **argv)
{
	int	col;
	int	row;
	int	v[4];

	col = vars[0] % size;
	row = vars[0] / size;
	v[0] = argv[1][(0 * size + col) * 2] - '0';
	v[1] = argv[1][(1 * size + col) * 2] - '0';
	v[2] = argv[1][(2 * size + row) * 2] - '0';
	v[3] = argv[1][(3 * size + row) * 2] - '0';
	if (is_distinct_in_col(size, data, vars[0])
		&& is_distinct_in_row(size, data, vars[0])
		&& is_top_visibility_valid(size, data, v[0], vars[0])
		&& is_bottom_visibility_valid(size, data, v[1], vars[0])
		&& is_left_visibility_valid(size, data, v[2], vars[0])
		&& is_right_visibility_valid(size, data, v[3], vars[0]))
	{
		vars[0]++;
		data[vars[0]] = '1';
	}
	else
	{
		data[vars[0]]++;
	}
}

void	rules_puzzle(char *data, int size, char **argv)
{
	int	vars[1];

	vars[0] = 0;
	data[vars[0]] = '1';
	while (vars[0] < 16 && vars[0] >= 0)
	{
		if (data[vars[0]] > '4')
		{
			data[vars[0]] = '\0';
			vars[0]--;
			if (vars[0] >= 0)
				data[vars[0]]++;
		}
		else
		{
			check(data, vars, size, argv);
		}
	}
	if (vars[0] > 0)
		ft_putmatrix(data, size);
	else
		ft_putstr("Error\n");
}

int	main(int argc, char **argv)
{
	char	data[17];
	int		size;

	if (argc < 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	size = 4;
	initialize_array(data, 17);
	rules_puzzle(data, size, argv);
	return (0);
}
