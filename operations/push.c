/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:31:09 by jurdiale          #+#    #+#             */
/*   Updated: 2026/06/10 14:22:32 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Mueve el tope de una pila a otra. Todas las operaciones 
	reciben t_count *count para contar en modo --bench y un parametro int print 
	para saber si deben imprimir su nombre o no (checker) print = 0 */

#include "push_swap.h"

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
