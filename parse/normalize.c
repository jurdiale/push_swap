/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:36:09 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 19:27:28 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Assigns each node an index from 0 to n-1 according to its relative rank.
** The node with the smallest value receives index=0, the largest index=n-1.
** For each node, counts how many nodes have a smaller value — that count is 
its index.
** Allows the algorithms to work with indices instead of arbitrary values.
*/

void	normalize(t_stack *a)
{
	t_stack	*current;
	t_stack	*temp;
	int		i;

	current = a;
	while (current != NULL)
	{
		i = 0;
		temp = a;
		while (temp != NULL)
		{
			if (temp->value < current->value)
				i++;
			temp = temp->next;
		}
		current->index = i;
		current = current->next;
	}
}

/* Computes the stack's disorder index: fraction of unordered pairs.
** For each pair (i,j) with i before j: if index[i] > index[j], it's a mistake.
** disorder = mistakes / total_pairs. Range: 0.0 (sorted) to 1.0 
(fully inverted).
** Called BEFORE sorting. Used by adaptative to choose the algorithm.
*/

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*temp;

	current = a;
	mistakes = 0;
	total_pairs = 0;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			total_pairs++;
			if (current->index > temp->index)
				mistakes++;
			temp = temp->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}
