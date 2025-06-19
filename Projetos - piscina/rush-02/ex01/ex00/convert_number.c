/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:48:55 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 18:16:54 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "dict.h"

int	handle_zero_case(t_dict *dict)
{
	char	*val;

	val = get_value("0", dict);
	if (!val)
		return (0);
	ft_putstr(val);
	ft_putchar('\n');
	return (1);
}

int	convert_number(char *number, t_dict *dict)
{
	int		len;
	int		full_len;
	char	*val;
	char	*padded;

	len = 0;
	while (number[len])
		len++;
	if (len == 1 && number[0] == '0')
		return (handle_zero_case(dict));
	full_len = ((len + 2) / 3) * 3;
	padded = pad_number(number, len, full_len);
	if (!padded)
		return (0);
	if (!process_triplet(padded, full_len, dict))
	{
		free(padded);
		return (0);
	}
	ft_putchar('\n');
	free(padded);
	return (1);
}

int	process_triplet(char *padded, int full_len, t_dict *dict)
{
	int		i;
	int		scale;
	int		first;
	char	triplet[4];

	i = 0;
	first = 0;
	while (i < full_len)
	{
		triplet[0] = padded[i++];
		triplet[1] = padded[i++];
		triplet[2] = padded[i++];
		triplet[3] = '\0';
		scale = (full_len - i) / 3;
		if (!handle_triple(triplet, dict, scale, &first))
			return (0);
	}
	return (1);
}
