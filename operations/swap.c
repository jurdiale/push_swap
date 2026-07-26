/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:54:42 by jurdiale          #+#    #+#             */
/*   Updated: 2026/06/10 13:56:15 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	swap intercambia los 2 primeros elementos de una pila. 
    Todas las operaciones reciben t_count *count para contar en modo --bench 
    y un parametro int print para saber si deben imprimir su nombre o no 
    (checker) print = 0 */

#include "push_swap.h"

void	sa(t_stack **a, int print, t_count *count)
{
	int	temp;

	if (!(*a) || !(*a)->next)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	if (print)
		write(1, "sa\n", 3);
	count->sa++;
	count->total++;
}

void	sb(t_stack **b, int print, t_count *count)
{
	int	temp;

	if (!(*b) || !(*b)->next)
		return ;
	temp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp;
	if (print)
		write(1, "sb\n", 3);
	count->sb++;
	count->total++;
}

void	ss(t_stack **a, t_stack **b, int print, t_count *count)
{
	int	temp_a;
	int	temp_b;

	if (!(*a) || !(*a)->next)
		return ;
	if (!(*b) || !(*b)->next)
		return ;
	temp_a = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp_a;
	temp_b = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp_b;
	if (print)
		write(1, "ss\n", 3);
	count->ss++;
	count->total++;
}
