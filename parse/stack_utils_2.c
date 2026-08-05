/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:49:13 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/05 16:33:54 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	meet_minimum(t_stack *a)
{
	int		minimo;
	t_stack	*current;

	minimo = a->index;
	current = a;
	while (current != NULL)
	{
		if (minimo > current->index)
			minimo = current->index;
		current = current->next;
	}
	return (minimo);
}

int	max(int a, int b)
{
	if (a>b)
		return (a);
	return (b);
}
