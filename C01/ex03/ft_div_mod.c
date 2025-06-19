/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:54:34 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/09 14:22:17 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int main ()
//{
// 	int a = 10;
// 	int b = 20;
// 	int div;
// 	int mod;
// 	printf("Divisão de %d e %d\n", a, b);
// 	ft_div_mod(a, b, &div, &mod);
// 	printf("Divisão =  %d\n Resto = %d\n", div, mod);
// 	return(0);
//}