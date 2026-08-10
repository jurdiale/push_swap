/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:33:16 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 18:45:55 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptative(t_stack **a, t_stack **b,
	float disorder, t_count *count)
{
	if (disorder < 0.2)
		lineal_algorithm(a, count);
	else if (disorder < 0.5)
		medium_algorithm(a, b, count);
	else
		complex_algorithm(a, b, count);
}
