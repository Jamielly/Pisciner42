/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:49:02 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/08 17:28:15 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_right_visibility_valid(int size, char *data, int vis, int pos)
{
	int		index;
	char	max_value;
	int		count;
	char	value;

	count = 0;
	max_value = 0;
	value = '\0';
	index = size - 1;
	while (index >= 0)
	{
	value = data[pos / size * size + index];
		if (max_value < value)
		{
		max_value = value;
		count++;
		}
	index--;
	}
	return (count <= vis);
}

int	is_left_visibility_valid(int size, char *data, int vis, int pos)
{
	int		index;
	char	max_value;
	int		count;
	char	value;

	count = 0;
	max_value = 0;
	value = '\0';
	index = 0;
	while (index < size)
	{
	value = data[pos / size * size + index];
		if (max_value < value)
		{
		max_value = value;
		count++;
		}
	index++;
	}
	return (count <= vis);
}

int	is_top_visibility_valid(int size, char *data, int vis, int pos)
{
	int		index;
	char	max_value;
	int		count;
	char	value;

	count = 0;
	max_value = 0;
	value = '\0';
	index = 0;
	while (index < size)
	{
	value = data[(pos % size) + (index * size)];
		if (max_value < value)
		{
		max_value = value;
		count++;
		}
	index++;
	}
	return (count <= vis);
}

int	is_bottom_visibility_valid(int size, char *data, int vis, int pos)
{
	int		index;
	char	max_value;
	int		count;
	char	value;

	count = 0;
	max_value = 0;
	value = '\0';
	index = size - 1;
	while (index >= 0)
	{
	value = data[(pos % size) + (size * index)];
		if (max_value < value)
		{
		max_value = value;
		count++;
		}
	index--;
	}
	return (count <= vis);
}
