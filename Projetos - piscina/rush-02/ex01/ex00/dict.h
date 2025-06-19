/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:30:14 by dcavalca          #+#    #+#             */
/*   Updated: 2025/06/15 21:17:37 by dcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_dict
{
	char			*num;
	char			*text;
	int				start_zeros;
	int				end_zeros;
	int				dict_zeros;
	struct s_dict	*next;
}	t_dict;

void	free_dict(t_dict *dict);
char	*get_value(char *key, t_dict *dict);
int		is_numeric(char *str);

#endif
