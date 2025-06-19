/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:42:03 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 19:58:05 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "utils.h"

int	print_units_only(char digits, t_dict *dict, int *first)
{
	char	num[2];
	char	*val;

	num[0] = digits;
	num[1] = '\0';
	val = get_value(num, dict);
	if (!val)
		return (0);
	print_with_space(val, first);
	return (1);
}

int	print_hundreds(char *digits, t_dict *dict, int *first)
{
	char	num[2];
	char	*val;

	if (digits[2] == '0')
		return (1);
	num[0] = digits[0];
	num[1] = '\0';
	val = get_value(num, dict);
	if (!val)
		return (0);
	print_with_space(val, first);
	val = get_value("100", dict);
	if (!val)
		return (0);
	print_with_space(val, first);
	return (2);
}

int	print_tens(char *digits, t_dict *dict, int *first)
{
	char	num[3];
	char	*val;

	if (digits[0] == '1')
	{
		num[0] = digits[0];
		num[1] = digits[1];
		num[2] = '\0';
		val = get_value(num, dict);
		if (!val)
			return (0);
		print_with_space(val, first);
		return (1);
	}
	if (digits[0] != '0')
	{
		num[0] = digits[1];
		num[1] = '0';
		num[2] = '\0';
		val = get_value(num, dict);
	}
	if (digits[1] != '0')
		return (print_units_only(digits[1], dict, first));
	return (1);
}

int	print_units(char unit, t_dict *dict, int *first)
{
	char	num[2];
	char	*val;

	if (unit == '0')
		return (1);
	num[0] = unit;
	num[1] = '\0';
	val = get_value(num, dict);
	if (!val)
		return (0);
	print_with_space(val, first);
	return (1);
}

int	print_scale(int scale, t_dict *dict, int *first)
{
	char	*val;
	char	*scales[3];

	scales[0] = "1000";
	scales[1] = "1000000";
	scales[2] = "1000000000";
	if (scale == 0)
		return (1);
	val = get_value(scales[scale - 1], dict);
	if (!val)
		return (0);
	print_with_space(val, first);
	return (1);
}
