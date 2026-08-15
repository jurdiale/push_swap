/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:31:09 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:45:10 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Moves the top node of a to the top of b.
** Moves the entire node (does not copy the value), redirecting pointers.
** Does nothing if a is empty.
*/

void	pb(t_stack **a, t_stack **b, int print, t_count *count)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print)
		write(1, "pb\n", 3);
	count->pb++;
	count->total++;
}

/* Moves the top node of b to the top of a.
** Identical to pb but in the opposite direction.
** Does nothing if b is empty.
*/

void	pa(t_stack **a, t_stack **b, int print, t_count *count)
{
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (print)
		write(1, "pa\n", 3);
	count->pa++;
	count->total++;
}
