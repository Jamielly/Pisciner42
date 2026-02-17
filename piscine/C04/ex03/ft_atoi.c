/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:44:37 by jamsilva          #+#    #+#             */
/*   Updated: 2026/01/30 15:45:13 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	signal;
	int	res;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	signal = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
				signal *= -1;
		}
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
	res = res * 10 + (str[i] - '0');
	i++;
	}
	return (res * signal);
}
