/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:03:45 by Jose              #+#    #+#             */
/*   Updated: 2026/08/11 04:14:48 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_a(t_stack **a, int pos_a, int size_a, t_count *count)
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

static void	rotate_b(t_stack **b, int pos_b, int size_b, t_count *count)
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

void	rotate_both(t_stack **a, t_stack **b, int better, t_count *count)
{
	int	pos_b;
	int	destination;
	int	pos_a;
	int	size_a;
	int	size_b;

	pos_b = position(*b, better);
	destination = meet_destination(*a, better);
	pos_a = position(*a, destination);
	size_a = stack_size(*a);
	size_b = stack_size(*b);
	if ((pos_b <= (size_b / 2)) && (pos_a <= (size_a / 2)))
	{
		while ((pos_b-- > 0) && (pos_a-- > 0))
			rr(a, b, 1, count);
	}
	if ((pos_b > (size_b / 2)) && (pos_a > (size_a / 2)))
	{
		while ((pos_b++ < size_b) && (pos_a++ < size_a))
			rrr(a, b, 1, count);
	}
	rotate_b(b, pos_b, size_b, count);
	rotate_a(a, pos_a, size_a, count);
}

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
