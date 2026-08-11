/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:30:45 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 23:03:23 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* El ultimo elemento pasa a ser el primero. Todas las operaciones 
	reciben t_count *count para contar en modo --bench y un parametro int print 
	para saber si deben imprimir su nombre o no (checker) print = 0 */

#include "../push_swap.h"

void	rra(t_stack **a, int print, t_count *count)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *a;
	*a = temp;
	if (print)
		write(1, "rra\n", 4);
	count->rra++;
	count->total++;
}

void	rrb(t_stack **b, int print, t_count *count)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *b;
	*b = temp;
	if (print)
		write(1, "rrb\n", 4);
	count->rrb++;
	count->total++;
}

void	rrr(t_stack **a, t_stack **b, int print, t_count *count)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*last_a;
	t_stack	*last_b;

	if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
		return ;
	last_a = *a;
	while (last_a->next->next)
		last_a = last_a->next;
	temp_a = last_a->next;
	last_a->next = NULL;
	temp_a->next = *a;
	*a = temp_a;
	last_b = *b;
	while (last_b->next->next)
		last_b = last_b->next;
	temp_b = last_b->next;
	last_b->next = NULL;
	temp_b->next = *b;
	*b = temp_b;
	if (print)
		write(1, "rrr\n", 4);
	count->rrr++;
	count->total++;
}
