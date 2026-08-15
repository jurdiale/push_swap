/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:45:23 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:47:59 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* The first element of a becomes the last one (rotate up).
** Traverses to the last node and attaches the former top at the end.
** Does nothing if a has fewer than 2 elements.
*/

void	ra(t_stack **a, int print, t_count *count)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
	count->ra++;
	count->total++;
}

/* The first element of b becomes the last one.
** Identical to ra but operates on b.
*/

void	rb(t_stack **b, int print, t_count *count)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*b) || !(*b)->next)
		return ;
	temp = *b;
	(*b) = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
	count->rb++;
	count->total++;
}

/* Static helper: performs the upward rotation on any stack.
** Used by rr to avoid duplicating rotation code.
*/

static void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

/* Rotates a and b upward simultaneously.
** Calls rotate_stack for each stack. Does not call ra+rb to avoid double 
counting.
** Only writes "rr" and increments the counter if at least one stack has 2 
or more elements.
*/

void	rr(t_stack **a, t_stack **b, int print, t_count *count)
{
	int	did_rotate;

	did_rotate = 0;
	if (*a && (*a)->next)
	{
		rotate_stack(a);
		did_rotate = 1;
	}
	if (*b && (*b)->next)
	{
		rotate_stack(b);
		did_rotate = 1;
	}
	if (!did_rotate)
		return ;
	if (print)
		write(1, "rr\n", 3);
	count->rr++;
	count->total++;
}
