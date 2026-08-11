/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:23:52 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/11 03:50:27 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_algorithm(t_stack **a, t_stack **b, t_count *count)
{
	while (stack_size(*a) > 3)
		pb(a, b, 1, count);
	order_3(a, count);
	while (*b != NULL)
	{
		rotate_minimum_b(b, count);
		phase_2(a, b, count);
	}
	phase_3(a, count);
}
