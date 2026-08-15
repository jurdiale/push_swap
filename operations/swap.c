/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:30:45 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:50:21 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swaps the first two elements of stack a.
** Swaps both value and index to keep consistency.
** If print=1 it writes "sa" to stdout. Counts the operation in count.
*/

void	sa(t_stack **a, int print, t_count *count)
{
	int	temp;
	int	temp_index;

	if (!(*a) || !(*a)->next)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	temp_index = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp_index;
	if (print)
		write(1, "sa\n", 3);
	count->sa++;
	count->total++;
}

/* Swaps the first two elements of stack b.
** Identical to sa but operates on b.
*/

void	sb(t_stack **b, int print, t_count *count)
{
	int	temp;
	int	temp_index;

	if (!(*b) || !(*b)->next)
		return ;
	temp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp;
	temp_index = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp_index;
	if (print)
		write(1, "sb\n", 3);
	count->sb++;
	count->total++;
}

/* Static helper: swaps value and index of the first two nodes.
** Used by ss to avoid duplicating the swap code.
*/

static void	swap_top(t_stack *stack)
{
	int	temp;
	int	temp_index;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
}

/* Swaps the first two elements of a and the first two elements of b 
simultaneously.
** Calls swap_top for each stack. Does not call sa+sb to avoid double counting.
** Only writes "ss" and increments the counter if at least one stack has 2 or 
more elements.
*/

void	ss(t_stack **a, t_stack **b, int print, t_count *count)
{
	int	did_swap;

	did_swap = 0;
	if (*a && (*a)->next)
	{
		swap_top(*a);
		did_swap = 1;
	}
	if (*b && (*b)->next)
	{
		swap_top(*b);
		did_swap = 1;
	}
	if (!did_swap)
		return ;
	if (print)
		write(1, "ss\n", 3);
	count->ss++;
	count->total++;
}
