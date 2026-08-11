/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:08:48 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/11 03:56:15 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse_flags(char **argv, int *flag_strategy, int *flag_bench)
{
	int	i;

	i = 1;
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			*flag_strategy = SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			*flag_strategy = MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			*flag_strategy = COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			*flag_strategy = ADAPTATIVE;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			*flag_bench = 1;
		else
			i = -1;
		i++;
	}
	return (i);
}
