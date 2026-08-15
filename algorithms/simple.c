/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:23:52 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/14 17:16:01 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Checks whether the stack is "circularly sorted": it has at most one
** break point between consecutive elements (including the last->first jump).
** A circularly sorted stack only needs rotations to become fully sorted.
*/

static int	is_circular(t_stack *a)
{
	t_stack	*current;
	int		breaks;

	if (!a)
		return (1);
	current = a;
	breaks = 0;
	while (current->next)
	{
		if (current->index > current->next->index)
			breaks++;
		current = current->next;
	}
	if (current->index > a->index)
		breaks++;
	return (breaks <= 1);
}

/* O(n) algorithm for nearly sorted stacks (disorder < 0.2).
** First verifies with is_circular whether the stack only needs rotations.
** If it is circular, rotates with ra or rra until the minimum reaches the top
** and returns 1.
** If it is not circular, returns 0 so that adaptative can use another algorithm.
*/

int	fast_path(t_stack **a, t_count *count)
{
	int	pos;
	int	size;

	if (!*a || !(*a)->next)
		return (1);
	if (is_circular(*a))
	{
		pos = position(*a, 0);
		size = stack_size(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a, 1, count);
		}
		else
		{
			while (pos++ < size)
				rra(a, 1, count);
		}
		return (1);
	}
	else
		return (0);
}

/* O(n^2) algorithm: insertion sort adapted for stacks.
** Phase 1: push everything to b except 3 elements. Phase 2: sort those 3 with 
order_3.
** Phase 3: insert from b into a using minimum-cost insertion (phase_2). 
Phase 4: rotate the minimum to the top.
*/

void	simple_algorithm(t_stack **a, t_stack **b, t_count *count)
{
	if (!fast_path(a, count))
	{
		while (stack_size(*a) > 3)
			pb(a, b, 1, count);
		order_3(a, count);
		phase_2(a, b, count);
		phase_3(a, count);
	}
}
