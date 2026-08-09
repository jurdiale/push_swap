/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:31:39 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/09 20:58:33 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_to_b(t_stack **a, t_stack **b, int size, t_count *count)
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

void	insert_to_a(t_stack **a, t_stack **b, t_count *count)
{
	int	better_index;

	better_index = 0;
	while (*b != NULL)
	{
		better_index = meet_better(a, b);
		rotate_both(a, b, better_index, count);
		pa (a, b, 1, count);
	}
}

void	medium_algorithm(t_stack **a, t_stack **b, t_count *count)
{
	while (stack_size(*a) > 3)
		push_to_b(a, b, stack_size(*a), count);
	order_3(a, count);
	while (*b != NULL)
	{
		rotate_minimum_b(b, count);
		insert_to_a(a, b, count);
	}
	rotate_min(a, count);
}
