/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:24:29 by jamsilva          #+#    #+#             */
/*   Updated: 2026/01/26 14:55:48 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	d;
	char	c;
	char	u;

	c = '0';
	while (c <= '7')
	{
		d = c + 1;
		while (d <= '8')
		{
			u = d + 1;
			while (u <= '9')
      {
				write(1, &c, 1);
				write(1, &d, 1);
				write(1, &u, 1);
				if (c < '7' || d < '8' || u < '9')
					write (1, ", ", 2);
			u++;
			}
		d++;
		}
		c++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
