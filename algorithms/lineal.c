/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:57:50 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/11 03:50:36 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lineal_algorithm(t_stack **a, t_count *count)
{
	int	swap;
	int	i;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < stack_size(*a) - 1)
		{
			if ((*a)->index > (*a)->next->index)
			{
				sa(a, 1, count);
				swap = 1;
			}
			ra(a, 1, count);
			i++;
		}
	}
	phase_3(a, count);
}
