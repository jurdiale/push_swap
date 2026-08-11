/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:49:13 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/10 23:03:23 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
