/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:31:39 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/11 03:45:58 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	exists_in_chunk(t_stack *a, int chunk, int chunk_size)
{
	while (a)
	{
		if (a->index >= chunk * chunk_size
			&& a->index < (chunk + 1) * chunk_size)
			return (1);
		a = a->next;
	}
	return (0);
}

void	phase_1(t_stack **a, t_stack **b, int size, t_count *count)
{
	int	chunk;
	int	chunk_size;

	chunk = 0;
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = size / 8;
	while (stack_size (*a) > 3)
	{
		if (((*a)->index >= chunk * chunk_size)
			&& (*a)->index < (chunk + 1) * chunk_size)
		{
			pb(a, b, 1, count);
			if ((*b)->index > chunk * chunk_size + chunk_size / 2)
				rb (b, 1, count);
		}
		else
			ra(a, 1, count);
		if (!exists_in_chunk(*a, chunk, chunk_size))
			chunk++;
	}
}

void	phase_2(t_stack **a, t_stack **b, t_count *count)
{
	int	better_index;

	better_index = 0;
	while (*b != NULL)
	{
		better_index = meet_better(*a, *b);
		rotate_both(a, b, better_index, count);
		pa (a, b, 1, count);
	}
}

void	phase_3(t_stack **a, t_count *count)
{
	long	size_a;

	size_a = stack_size(*a);
	while ((*a)->index != 0)
	{
		if (position(*a, 0) <= size_a / 2)
			ra(a, 1, count);
		else
			rra(a, 1, count);
	}
}

void	medium_algorithm(t_stack **a, t_stack **b, t_count *count)
{
	phase_1(a, b, stack_size(*a), count);
	order_3(a, count);
	while (*b != NULL)
	{
		rotate_minimum_b(b, count);
		phase_2(a, b, count);
	}
	phase_3(a, count);
}
