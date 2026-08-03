/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:49:13 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/03 14:07:12 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	encontrar_minimo(t_stack *a)
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
