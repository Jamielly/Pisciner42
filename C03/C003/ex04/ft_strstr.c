/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:52:27 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/18 09:33:25 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
		j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
	i++;
	}
	return (NULL);
}
/*int main()
{
	char test1[] = "Busca string";
	char test2[] = "string";

	printf("%s\n", ft_strstr(test1,test2));
	return (0);
}*/