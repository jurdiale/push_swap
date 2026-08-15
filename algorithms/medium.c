/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:31:39 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/14 17:18:04 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* Finds the next element belonging to the current chunk and rotates
** stack A in the shortest direction to bring it to the top.
*/

static int	move_chunk(t_stack **a, int chunk, int chunk_size, t_count *count)
{
	int	pos;

	pos = find_next(*a, chunk, chunk_size);
	if (pos == -1)
		return (0);
	if (pos <= stack_size(*a) / 2)
		ra(a, 1, count);
	else
		rra(a, 1, count);
	return (1);
}

/* Splits the indices into chunks and pushes them to b in an ordered manner.
** chunk_size = size/8 (minimum 20). If the top belongs to the current 
chunk -> pb.
** If not, uses find_next to rotate with ra or rra toward the closest 
element of the chunk.
** When the chunk becomes empty in a, it moves on to the next chunk.
*/

void	phase_1(t_stack **a, t_stack **b, int size, t_count *count)
{
	int	chunk_size;
	int	chunk;

	chunk_size = (ft_sqrt(size) * 5);
	if (chunk_size < 20)
		chunk_size = 20;
	chunk = 0;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index >= chunk * chunk_size
			&& (*a)->index < (chunk + 1) * chunk_size)
			pb(a, b, 1, count);
		else if (!move_chunk(a, chunk, chunk_size, count))
			chunk++;
	}
}

/* Inserts elements from b into a always choosing the one with the lowest cost.
** For each iteration: meet_better finds the optimal element, rotate_both
** positions both stacks, and pa inserts it in the correct position.
*/

void	phase_2(t_stack **a, t_stack **b, t_count *count)
{
	int	better_index;

	while (*b != NULL)
	{
		better_index = meet_better(*a, *b);
		rotate_both(a, b, better_index, count);
		pa(a, b, 1, count);
	}
}

/* Rotates a until the element with index = 0 (the minimum) reaches the top.
** Chooses ra or rra depending on whether the minimum is in the first or 
second half.
*/

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

/* O(n*sqrt(n)) algorithm: Turkish-style chunk-based method.
** Executes in order: phase_1 (chunk-based pushing), order_3 
(sort the remainder),
** phase_2 (cost-based insertion), phase_3 (rotate minimum to the top).
*/

void	medium_algorithm(t_stack **a, t_stack **b, t_count *count)
{
	phase_1(a, b, stack_size(*a), count);
	order_3(a, count);
	phase_2(a, b, count);
	phase_3(a, count);
}
