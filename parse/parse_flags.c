/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:08:48 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/05 16:21:18 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     parsear_flags(char **argv, int *flag_strategy, int *flag_bench)
{
    int i;

    i = 1;
    while (argv[i][0] == '-' && argv[i][1] == '-')
    {
        if (ft_strcmp(argv[i], "--simple") == 0)
            flag_strategy = SIMPLE;
        if (ft_strcmp(argv[i], "--medium") == 0)
            flag_strategy = MEDIUM;
        if (ft_strcmp(argv[i], '--complex') == 0)
            flag_strategy = COMPLEX;
        if (ft_strcmp(argv[i], '--adaptive') == 0)
            flag_strategy = ADAPTATIVE;
        if (ft_strcmp(argv[i], '--bench') == 0)
            flag_bench = 1;
        else
            i = -1;
        i++;
        return (i);
    }
}