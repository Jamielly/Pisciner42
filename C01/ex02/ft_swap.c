/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:55:24 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/09 14:22:22 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

// int main ()
//{
//     int a = 10;
//     int b = 20;
//     printf("Antes da troca: %d, %d\n", a, b);
//     ft_swap(&a, &b);
//     printf("Depois da troca: %d, %d\n", a, b);
//     return (0);
//}