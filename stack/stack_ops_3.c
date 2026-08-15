/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 20:04:10 by Jose              #+#    #+#             */
/*   Updated: 2026/08/13 12:05:25 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Case 1 of rotate_both: both elements are in the first half of their stacks.
** Uses rr while both still need upward rotation, then finishes with ra/rb 
separately.
** Minimizes operations by leveraging rr whenever possible.
*/

static void	rotate_up_both(t_stack **a, t_stack **b,
		t_rots rots, t_count *count)
{
	while (rots.pa > 0 && rots.pb > 0)
	{
		rr(a, b, 1, count);
		rots.pa--;
		rots.pb--;
	}
	while (rots.pa > 0)
	{
		ra(a, 1, count);
		rots.pa--;
	}
	while (rots.pb > 0)
	{
		rb(b, 1, count);
		rots.pb--;
	}
}

/* Case 2 of rotate_both: both elements are in the second half of their stacks.
** Uses rrr while both still need downward rotation, then finishes with rra/rrb 
separately.
** Minimizes operations by leveraging rrr whenever possible.
*/

static void	rotate_down_both(t_stack **a, t_stack **b,
		t_rots rots, t_count *count)
{
	while (rots.pa > 0 && rots.pb > 0)
	{
		rrr(a, b, 1, count);
		rots.pa--;
		rots.pb--;
	}
	while (rots.pa > 0)
	{
		rra(a, 1, count);
		rots.pa--;
	}
	while (rots.pb > 0)
	{
		rrb(b, 1, count);
		rots.pb--;
	}
}

/* Cases 3 and 4 of rotate_both: one element in the first half and the other 
in the second.
** rr/rrr cannot be used. Rotates each stack independently in its optimal 
direction.
** Case 3: a in first half (ra) + b in second half (rotate_b_down).
** Case 4: a in second half (rotate_a_down) + b in first half (rb).
*/

static void	rotate_mixed(t_stack **a, t_stack **b,
		t_rots rots, t_count *count)
{
	if (rots.pa <= rots.size_a / 2)
	{
		while (rots.pa-- > 0)
			ra(a, 1, count);
		rotate_b_down(b, rots, count);
	}
	else
	{
		rotate_a_down(a, rots, count);
		while (rots.pb-- > 0)
			rb(b, 1, count);
	}
}

/* Positions the element better at the top of b and its destination at the 
top of a.
** Computes positions and sizes in t_rots, then delegates to the correct case:
** rotate_up_both, rotate_down_both, or rotate_mixed depending on each 
element's position.
** After this function, pa inserts better into its correct position in a.
*/

void	rotate_both(t_stack **a, t_stack **b,
		int better, t_count *count)
{
	t_rots	rots;

	rots.pa = position(*a, meet_destination(*a, better));
	rots.pb = position(*b, better);
	rots.size_a = stack_size(*a);
	rots.size_b = stack_size(*b);
	if (rots.pa <= rots.size_a / 2 && rots.pb <= rots.size_b / 2)
		rotate_up_both(a, b, rots, count);
	else if (rots.pa > rots.size_a / 2 && rots.pb > rots.size_b / 2)
	{
		rots.pa = rots.size_a - rots.pa;
		rots.pb = rots.size_b - rots.pb;
		rotate_down_both(a, b, rots, count);
	}
	else
		rotate_mixed(a, b, rots, count);
}

int	ft_sqrt(int n)
{
	int	count;

	count = 1;
	while (count * count < n)
		count++;
	return (count);
}
