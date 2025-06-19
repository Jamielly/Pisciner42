/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:21:14 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 20:17:16 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "dict.h"

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	print_with_space(char *str, int *first);
int		convert_number(char *number, t_dict *dict);
char	*pad_number(char *number, int len, int full_len);
int		process_triplet(char *padded, int full_len, t_dict *dict);
int		handle_triple(char *triplet, t_dict *dict, int scale, int *first);
t_dict	*load_dict(const char *filename);

#endif
