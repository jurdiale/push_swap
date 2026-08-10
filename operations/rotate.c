/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:45:23 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 18:55:59 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* El primer elemento pasa a ser el ultimo. Todas las operaciones 
	reciben t_count *count para contar en modo --bench y un parametro int print 
	para saber si deben imprimir su nombre o no (checker) print = 0 */

#include "push_swap.h"

void	ra(t_stack **a, int print, t_count *count)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
	count->ra++;
	count->total++;
}

void	rb(t_stack **b, int print, t_count *count)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*b) || !(*b)->next)
		return ;
	temp = *b;
	(*b) = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
	count->rb++;
	count->total++;
}

void	rr(t_stack **a, t_stack **b, int print, t_count *count)
{
	t_stack	*last_a;
	t_stack	*last_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
		return ;
	temp_a = *a;
	(*a) = (*a)->next;
	last_a = *a;
	while (last_a->next)
		last_a = last_a->next;
	last_a->next = temp_a;
	temp_a->next = NULL;
	temp_b = *b;
	(*b) = (*b)->next;
	last_b = *b;
	while (last_b->next)
		last_b = last_b->next;
	last_b->next = temp_b;
	temp_b->next = NULL;
	if (print)
		write(1, "rr\n", 3);
	count->rr++;
	count->total++;
}
