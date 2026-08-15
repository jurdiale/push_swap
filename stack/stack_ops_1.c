/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:49:11 by Jose              #+#    #+#             */
/*   Updated: 2026/08/12 16:56:49 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Finds the successor of index in a: the node with the smallest index
** that is greater than index. That node must be at the top of a before pa.
** If index is greater than all elements, returns meet_minimum(a) for circular 
insertion.
** Example: a=[0,1,3], index=2 -> returns 3 (the successor of 2).
*/

int	meet_destination(t_stack *a, int index)
{
	int		destination;
	int		max;
	t_stack	*temp;

	max = meet_max(a);
	destination = max;
	temp = a;
	while (temp != NULL)
	{
		if (temp->index > index && temp->index < destination)
			destination = temp->index;
		temp = temp->next;
	}
	if (index > max)
		destination = meet_minimum(a);
	return (destination);
}

/* Computes the number of operations required to insert the element
** index_b from b into its correct position in a.
** Case 1 (both in the first half): max(pos_b, pos_a) using rr.
** Case 2 (both in the second half): max(size-pos_b, size-pos_a) using rrr.
** Cases 3 and 4 (different halves): sum of independent movements.
*/

int	calcule_cost(t_stack *a, t_stack *b, int index_b)
{
	int	pos_b;
	int	destination;
	int	pos_a;
	int	size_a;
	int	size_b;

	pos_b = position(b, index_b);
	destination = meet_destination(a, index_b);
	pos_a = position(a, destination);
	size_a = stack_size(a);
	size_b = stack_size(b);
	if ((pos_b <= (size_b / 2)) && (pos_a <= (size_a / 2)))
		return (max(pos_b, pos_a));
	if ((pos_b > (size_b / 2)) && (pos_a > (size_a / 2)))
		return (max(size_b - pos_b, size_a - pos_a));
	if ((pos_b <= (size_b / 2)) && (pos_a > (size_a / 2)))
		return (pos_b + (size_a - pos_a));
	if ((pos_b > (size_b / 2)) && (pos_a <= (size_a / 2)))
		return ((size_b - pos_b) + pos_a);
	return (0);
}

/* Iterates through b and finds the element with the lowest insertion cost in a.
** Calls calcule_cost for each element in b and returns the index of the 
best one.
** Used in phase_2 to decide which element of b to insert next.
*/

int	meet_better(t_stack *a, t_stack *b)
{
	int		better;
	int		better_index;
	int		cost;
	t_stack	*temp;

	better = INT_MAX;
	better_index = b->index;
	temp = b;
	while (temp != NULL)
	{
		cost = calcule_cost(a, b, temp->index);
		if (cost < better)
		{
			better = cost;
			better_index = temp->index;
		}
		temp = temp->next;
	}
	return (better_index);
}

/* Sorts exactly 3 elements in a with the minimum number of operations (max 2).
** Identifies the pattern of the 3 indices and applies the direct solution:
** [2,1,3] = sa
** [1,3,2] = rra + sa
** [2,3,1] = ra
** [1,2,0] = rra
** [2,1,0] = sa + rra
*/

void	order_3(t_stack **a, t_count *count)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (second < first && first < third && second < third)
		sa(a, 1, count);
	else if (first < third && third < second && first < second)
	{
		rra(a, 1, count);
		sa(a, 1, count);
	}
	else if (second < third && third < first && second < first)
		ra(a, 1, count);
	else if (third < first && first < second && third < second)
		rra(a, 1, count);
	else if (third < second && second < first && third < first)
	{
		sa(a, 1, count);
		rra(a, 1, count);
	}
	return ;
}

/* Sorts exactly 2 elements in a.
** If the top is greater than the second, applies sa.
*/

void	order_2(t_stack **a, t_count *count)
{
	if (((*a)->index) > ((*a)->next->index))
		sa(a, 1, count);
}
