/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 09:10:29 by hemaciel          #+#    #+#             */
/*   Updated: 2025/06/01 13:34:53 by rcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_conditions(int x, int y, int cntx, int cnty)
{
	if ((cntx == 1) && (cnty == 1 || cnty == y))
		ft_putchar('A');
	else if ((cntx == x) && (cnty == 1 || cnty == y))
		ft_putchar('C');
	else if (cntx == 1 || cntx == x || cnty == 1 || cnty == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cntx;
	int	cnty;

	cntx = 1;
	cnty = 1;
	if (x > 0 && y > 0)
	{
		while (cnty <= y)
		{
			while (cntx <= x)
			{
				ft_conditions(x, y, cntx, cnty);
				cntx++;
			}
			ft_putchar('\n');
			cntx = 1;
			cnty++;
		}
	}
}
