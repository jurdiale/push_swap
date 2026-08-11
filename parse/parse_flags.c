/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:08:48 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/11 13:12:47 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse_flags(char **argv, t_flags *flag)
{
	int	i;

	i = 1;
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			flag->strategy = SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			flag->strategy = MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			flag->strategy = COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			flag->strategy = ADAPTATIVE;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			flag->bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}
