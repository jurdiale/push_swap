/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:37:39 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 21:29:52 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_order(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	execute_operation(t_stack **a, t_stack **b,
	char *line, t_count *count)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 0, count);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 0, count);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 0, count);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0, count);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 0, count);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 0, count);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 0, count);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 0, count);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 0, count);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 0, count);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0, count);
	else
		error_exit(a, b);
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
