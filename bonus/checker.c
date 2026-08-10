/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:33:21 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 21:38:21 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	read_and_execute(t_stack **a, t_stack **b, t_count *count)
{
	char	*linea;

	linea = get_next_line(0);
	while (linea != NULL)
	{
		execute_operation(linea, a, b, count);
		free(linea);
		linea = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_count	count;
	char	**numbers;

	a = NULL;
	b = NULL;
	numbers = NULL;
	ft_memset(&count, 0, sizeof(t_count));
	if (argc == 1)
		return (0);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	build_stack(&a, &b, numbers);
	if (argc == 2)
		free_numbers(numbers);
	read_and_execute(&a, &b, &count);
	if (is_order(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&a, &b);
	return (0);
}
