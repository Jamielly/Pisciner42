/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:01:24 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 20:21:20 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "dict.h"
#include "nulp.h"

int	ft_strcmp(char *s1, char *s2);

char	*get_value(char *key, t_dict *dict)
{
	t_dict	*current;

	current = dict;
	while (current != NULP)
	{
		if (ft_strcmp(current->num, key) == 0)
		{
			return (current->text);
		}
		current = current->next;
	}
	return (NULP);
}
