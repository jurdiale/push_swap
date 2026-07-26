/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:37 by jurdiale          #+#    #+#             */
/*   Updated: 2026/06/11 15:47:15 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack **a)
{
    t_stack *temp;

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