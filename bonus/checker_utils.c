/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:37:39 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 23:01:44 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_numbers(char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j] != NULL)
	{
		free(numbers[j]);
		j++;
	}
	free(numbers);
}

void	free_all(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	build_stack(t_stack **a, t_stack **b, char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j] != NULL)
	{
		if (!is_valid(numbers[j]))
			error_exit(a, b);
		push_stack(a, (int)ft_atol(numbers[j]));
		j++;
	}
	if (there_are_duplicates(*a))
		error_exit(a, b);
	normalize(*a);
}
