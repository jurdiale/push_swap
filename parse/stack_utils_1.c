/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:37 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:53:30 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Frees all nodes of the stack and sets the pointer to NULL.
** Stores next before free to avoid accessing freed memory.
*/

void	free_stack(t_stack **a)
{
	t_stack	*temp;

	while (*a != NULL)
	{
		temp = (*a)->next;
		free (*a);
		*a = temp;
	}
	*a = NULL;
}

/* Creates a new node with value and inserts it at the top of the stack.
** The index is initialized to 0 — it will be assigned later with normalize.
** Returns 0 if malloc fails, 1 if it succeeds.
*/

int	push_stack(t_stack **a, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->index = 0;
	new->next = *a;
	*a = new;
	return (1);
}

/* Counts and returns the number of nodes in the stack.
*/

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

/* Returns the physical position of the node with the given index.
** 0 = top, 1 = second, etc. Returns -1 if not found.
*/

int	position(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

/* Returns the maximum index value present in the stack.
** Used as a starting point in meet_destination.
*/

int	meet_max(t_stack *a)
{
	int		max;
	t_stack	*current;

	max = a->index;
	current = a;
	while (current != NULL)
	{
		if (max < current->index)
			max = current->index;
		current = current->next;
	}
	return (max);
}
