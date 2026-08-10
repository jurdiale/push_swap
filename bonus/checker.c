/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:33:21 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 18:17:36 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_order(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	execute_operation(t_stack **a, t_stack **b,
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

static	void	build_stack(t_stack **a, t_stack **b, char **argv, int argc)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (!is_valid(argv[j]))
			error_exit(a, b);
		push_stack(a, (int)ft_atol(argv[j]));
		j++;
	}
	if (there_are_duplicates(*a))
		error_exit(a, b);
	normalize(*a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_count	count;
	char	*linea;

	a = NULL;
	b = NULL;
	ft_memset(&count, 0, sizeof(t_count));
	if (argc == 1)
		return (0);
	build_stack(&a, &b, argv, argc);
	linea = get_next_line(0);
	while (linea != NULL)
	{
		execute_operation(linea, &a, &b, &count);
		free(linea);
		linea = get_next_line(0);
	}
	if (is_order(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
