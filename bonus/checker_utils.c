/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:37:39 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:42:30 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Frees both stacks a and b.
** Used at the end of the checker's main to clean up all allocated memory.
*/

void	free_all(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

/* Builds stack a for the checker by iterating through numbers from 
right to left.
** The reverse traversal ensures that numbers[0] ends up at the top of a.
** Validates each number, detects duplicates, and normalizes. Calls error_exit 
if any error occurs.
*/

void	build_stack(t_stack **a, t_stack **b, char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!is_valid(numbers[j]))
			error_exit(a, b);
		push_stack(a, (int)ft_atol(numbers[j]));
		j--;
	}
	if (there_are_duplicates(*a))
		error_exit(a, b);
	normalize(*a);
}
