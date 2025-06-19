/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:55:22 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/09 14:22:14 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
// int main ()
// {
// 	int a = 10;
// 	int b = 20;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("Divisão = %d\n", a);
// 	printf("Resto = %d", b);
// }