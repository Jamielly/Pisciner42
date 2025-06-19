/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:38:29 by mmaquine          #+#    #+#             */
/*   Updated: 2025/06/08 16:51:03 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_distinct_in_row(int size, char *data, int position)
{
	int				index;
	unsigned char	value;
	unsigned char	map[256];

	initialize_array2(map, 256);
	value = '\0';
	index = 0;
	while (index < size)
	{
		value = (unsigned char) data[position / size * size + index];
		if (!value)
		{
			index++;
			continue ;
		}
		if (map[value] == 1)
		{
			return (0);
		}
		map[value] = 1;
		index++;
	}
	return (1);
}

int	is_distinct_in_col(int size, char *data, int position)
{
	int				index;
	unsigned char	value;
	unsigned char	map[256];

	initialize_array2(map, 256);
	value = '\0';
	index = 0;
	while (index < size)
	{
		value = (unsigned char) data[(position % size) + (index * size)];
		if (!value)
		{
			index++;
			continue ;
		}
		if (map[value] == 1)
		{
			return (0);
		}
		map[value] = 1;
		index++;
	}
	return (1);
}
