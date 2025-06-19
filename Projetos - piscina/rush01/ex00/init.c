/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:36:24 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/08 17:04:17 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_array(char *arr, int items)
{
	int	index;

	index = 0;
	while (index < items)
	{
	arr[index] = '\0';
	index++;
	}
}

void	ft_putstr(char	*str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putmatrix(char *str, int size)
{
	int	index;

	index = 0;
	while (index < size * size)
	{
		write(1, &str[index], 1);
		if (index % size == size - 1)
			write(1, "\n", 1);
		index++;
	}
}

void	initialize_array2(unsigned char *arr, int items)
{
	int	index;

	index = 0;
	while (index < items)
	{
	arr[index] = '\0';
	index++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
