/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:03:45 by Jose              #+#    #+#             */
/*   Updated: 2026/08/12 16:58:33 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Rotates a to bring the node at position pos_a to the top.
** If pos_a <= size_a/2 it uses ra (faster from the top).
** If pos_a > size_a/2 it uses rra (faster from the bottom).
*/

void	rotate_a(t_stack **a, int pos_a, int size_a, t_count *count)
{
	if (pos_a <= (size_a / 2))
	{
		while (pos_a > 0)
		{
			ra(a, 1, count);
			pos_a--;
		}
	}
	else
	{
		while (pos_a < (size_a))
		{
			rra(a, 1, count);
			pos_a++;
		}
	}
}

/* Rotates b to bring the node at position pos_b to the top.
** Identical to rotate_a but operates on b.
*/

void	rotate_b(t_stack **b, int pos_b, int size_b, t_count *count)
{
	if (pos_b <= (size_b / 2))
	{
		while (pos_b > 0)
		{
			rb(b, 1, count);
			pos_b--;
		}
	}
	else
	{
		while (pos_b < (size_b))
		{
			rrb(b, 1, count);
			pos_b++;
		}
	}
}

/* Brings the element with the smallest index in b to the top.
** Chooses rb or rrb depending on whether the minimum is in the first or 
second half.
** Used by simple_algorithm to always insert the smallest element first.
*/

void	rotate_minimum_b(t_stack **b, t_count *count)
{
	int	minimum;
	int	pos;
	int	size;

	minimum = meet_minimum(*b);
	pos = position(*b, minimum);
	size = stack_size(*b);
	if (pos <= (size / 2))
	{
		while ((*b)->index != minimum)
			rb(b, 1, count);
	}
	else
	{
		while ((*b)->index != minimum)
			rrb(b, 1, count);
	}
}

/* Moves the element of a down to its position using rra.
** Computes how many rra are needed: size_a - pos_a.
** Helper for rotate_mixed when a is in the second half.
*/

void	rotate_a_down(t_stack **a, t_rots rots, t_count *count)
{
	int	n;

	n = rots.size_a - rots.pa;
	while (n-- > 0)
		rra(a, 1, count);
}

/* Moves the element of b down to its position using rrb.
** Computes how many rrb are needed: size_b - pos_b.
** Helper for rotate_mixed when b is in the second half.
*/

void	rotate_b_down(t_stack **b, t_rots rots, t_count *count)
{
	int	n;

	n = rots.size_b - rots.pb;
	while (n-- > 0)
		rrb(b, 1, count);
}
