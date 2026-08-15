/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:33:21 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:44:23 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Executes the operation specified by line on stacks a and b.
** Compares line (which includes the final newline) with each valid operation.
** If the operation is not recognized, calls error_exit.
*/

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

/* Checks whether stack a is sorted in ascending order by index.
** Iterates through the stack comparing each node with the next one.
** Returns 1 if it is sorted, 0 if any inversion is found.
*/

static int	is_order(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

/* Reads operations from stdin line by line using get_next_line and executes 
them.
** Each line includes the newline — execute_operation uses it for comparison.
** Frees each line after executing it.
*/

static void	read_and_execute(t_stack **a, t_stack **b, t_count *count)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		execute_operation(a, b, line, count);
		free(line);
		line = get_next_line(0);
	}
}

/* Entry point of the checker. Builds the stack from the arguments,
** reads and executes operations from stdin with read_and_execute,
** and checks whether a ends up sorted and b empty. Prints "OK" or "KO" to 
stdout.
*/

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
