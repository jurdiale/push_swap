/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:49:13 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/14 17:16:01 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Returns the minimum index value present in the stack.
** Used in meet_destination when the element to insert is greater than all 
others.
*/

int	meet_minimum(t_stack *a)
{
	int		minimum;
	t_stack	*current;

	minimum = a->index;
	current = a;
	while (current != NULL)
	{
		if (minimum > current->index)
			minimum = current->index;
		current = current->next;
	}
	return (minimum);
}

/* Returns the greater of two integers.
** Implemented manually because max does not exist in the 42 standard library.
*/

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/* Returns the physical position of the node with the highest index in b.
** Used internally to optimize insertion in phase_2.
*/

int	position_of_max(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	max = -1;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			pos = i;
		}
		i++;
		b = b->next;
	}
	return (pos);
}

/* Finds the position of the first element in a that belongs to the given chunk.
** Returns the physical position or -1 if there are no elements from that 
chunk in a.
** Used in phase_1 to decide whether to rotate with ra or rra toward the next
chunk element.
*/

int	find_next(t_stack *a, int chunk, int chunk_size)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= chunk * chunk_size
			&& a->index < (chunk + 1) * chunk_size)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}
