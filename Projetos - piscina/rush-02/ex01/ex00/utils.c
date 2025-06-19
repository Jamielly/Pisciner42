/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:08:07 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 19:03:27 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_with_space(char *str, int *first)
{
	if (!str)
		return ;
	if (!*first)
		ft_putchar(' ');
	ft_putstr(str);
	*first = 0;
}
