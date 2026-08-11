/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:33:16 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 22:56:43 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
