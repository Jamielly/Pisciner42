/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:13:59 by jamsilva          #+#    #+#             */
/*   Updated: 2026/02/04 13:29:31 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && s1 == s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_swap(int argc, char **argv)
{
	int			i;
	int			j;
	char		*tmp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
					tmp = argv[i];
					argv[i] = argv[j];
					argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	ft_swap(argc, argv);
	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
		{
			write(1, &argv[i][k], 1);
		k++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
