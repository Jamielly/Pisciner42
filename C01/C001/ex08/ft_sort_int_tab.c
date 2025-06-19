/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:33:47 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/09 14:22:45 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	swapped;

	if (size <= 1)
		return ;
		swapped = 1;
	while (swapped)
	{
	swapped = 0;
	i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			swapped = 1;
			}
		i++;
		}
	}
}

/*int main()
{
	int arr[6] = {9, 2, 5, 0, 7, 3};
	int size = 6;
	int i = 0;

	ft_sort_int_tab(arr, size);
	while (i < size)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
		{
			printf(", ");
		}
        i++;
	}
	printf("\n");
	return (0);
}
*/