/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:30:45 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:46:30 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* The last element of a becomes the first one (rotate down).
** Reaches the second-to-last with last->next->next, disconnects the last
** and places it at the top. Does nothing if a has fewer than 2 elements.
*/

void	rra(t_stack **a, int print, t_count *count)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *a;
	*a = temp;
	if (print)
		write(1, "rra\n", 4);
	count->rra++;
	count->total++;
}

/* The last element of b becomes the first one.
** Identical to rra but operates on b.
*/

void	rrb(t_stack **b, int print, t_count *count)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *b;
	*b = temp;
	if (print)
		write(1, "rrb\n", 4);
	count->rrb++;
	count->total++;
}

/* Static helper: performs the downward rotation on any stack.
** Used by rrr to avoid duplicating code.
*/

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	last = *stack;
	while (last->next->next)
		last = last->next;
	before_last = last;
	last = last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* Rotates a and b downward simultaneously.
** Calls reverse_rotate_stack for each stack. Does not call rra+rrb to 
avoid double counting.
*/

void	rrr(t_stack **a, t_stack **b, int print, t_count *count)
{
	int	did_rotate;

	did_rotate = 0;
	if (*a && (*a)->next)
	{
		reverse_rotate_stack(a);
		did_rotate = 1;
	}
	if (*b && (*b)->next)
	{
		reverse_rotate_stack(b);
		did_rotate = 1;
	}
	if (!did_rotate)
		return ;
	if (print)
		write(1, "rrr\n", 4);
	count->rrr++;
	count->total++;
}
