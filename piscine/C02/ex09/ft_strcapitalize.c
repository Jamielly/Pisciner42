/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:05:59 by jamsilva          #+#    #+#             */
/*   Updated: 2026/01/24 15:09:43 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	newp;

	i = 0;
	newp = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (newp && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!newp && (str[i] >= 'A' && str[i] <= 'Z'))
					str[i] += 32;
				newp = 0;
		}
		else
				newp = 1;
			i++;
	}
	return (str);
}
