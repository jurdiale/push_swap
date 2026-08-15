/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:33:16 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/13 16:19:49 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Selects the optimal algorithm according to the disorder index calculated 
earlier:
** disorder == 0.0: already sorted, does nothing.
** disorder < 0.2: tries lineal_algorithm (O(n)). If it fails, continues.
** disorder < 0.5: medium_algorithm O(n*sqrt(n)).
** disorder >= 0.5: complex_algorithm O(n*log(n)).
*/

void	adaptive(t_stack **a, t_stack **b,
		float disorder, t_count *count)
{
	if (disorder == 0)
		return ;
	if (disorder < 0.2)
		simple_algorithm(a, b, count);
	else if (disorder < 0.5)
		medium_algorithm(a, b, count);
	else
		complex_algorithm(a, b, count);
}
