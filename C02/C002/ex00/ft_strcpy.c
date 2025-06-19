/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasilva- <jasilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:43:47 by jasilva-          #+#    #+#             */
/*   Updated: 2025/06/13 14:45:37 by jasilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src)
	{
	*dest = *src;
	dest++;
	src++;
	}
	*dest = '\0';
	return (start);
}

/*int main()
{
    char src[] = {"Bolo de chocolate com cobertura de cenoura"};
    char dest[50];

    ft_strcpy(dest, src);
    printf("String fonte: %s\n", dest);
    return (0); 
}*/