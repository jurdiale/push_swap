/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:08:48 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:51:59 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Iterates through argv starting from index 1 while the arguments begin with 
"--".
** Sets flag->strategy according to the flag found, and flag->bench if --bench 
is present.
** Returns the index where the numbers begin, or -1 if an unknown flag is 
encountered.
*/

int	parse_flags(char **argv, t_flags *flag)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			flag->strategy = SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			flag->strategy = MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			flag->strategy = COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			flag->strategy = ADAPTIVE;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			flag->bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}
