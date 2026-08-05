/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:37 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/05 16:34:08 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	position(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == index)
			return (1);
		stack = stack->next;
		i++;
	}
	return (-1);
}

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
