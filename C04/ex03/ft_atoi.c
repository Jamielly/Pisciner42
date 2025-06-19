/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:45:39 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/19 11:57:58 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sinal;
	int	res;

	i = 0;
	res = 0;
	sinal = 1;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
		sinal *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
	res = res * 10 + (str[i] - '0');
	i++;
	}
	return (sinal * res);
}

/*int main()
{
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	printf("%d\n", ft_atoi("  ++++5678"));
  printf("%d\n", ft_atoi(" -+--+42")); 
	return (0);
}*/