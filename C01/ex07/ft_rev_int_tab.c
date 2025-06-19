/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:38:13 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/08 12:12:42 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	begin;
	int	end;

	begin = 0;
	end = size - 1;
	while (begin < end)
	{
		temp = tab[begin];
		tab[begin] = tab[end];
		tab[end] = temp;
		begin++;
		end--;
	}
}

/*int	main(void)
{
	int	arr[6];
	int	i;

	arr[6] = {6, 5, 4, 3, 2, 1};
	i = 0;
	ft_rev_int_tab(arr, 6);
	while (i < 6)
	{
		printf("%d", arr[i]);
		if (i < 5)
		{
			printf(", ");
			i++;
		}
	}
	printf("\n");
	return (0);
}*/
