/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:35:45 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/13 19:32:51 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initializes a and b to NULL and sets all counters in count to 0.
** Called at the beginning of main before any operation.
*/

static void	init_all(t_stack **a, t_stack **b, t_count *count)
{
	*a = NULL;
	*b = NULL;
	ft_memset(count, 0, sizeof(t_count));
}

/* Computes disorder and size, then selects and executes the correct algorithm.
** For size 2 uses order_2, for size 3 uses order_3, and for size > 3 uses the
** algorithm indicated by flags.strategy. If flags.bench is set, calls bench at 
the end.
*/

static void	execute_algorithms(t_stack **a, t_stack **b, t_count *count,
	t_flags flags)
{
	int		size;
	float	disorder;

	disorder = compute_disorder(*a);
	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (order_2(a, count));
	if (size == 3)
		return (order_3(a, count));
	if (flags.strategy == SIMPLE)
		simple_algorithm(a, b, count);
	else if (flags.strategy == MEDIUM)
		medium_algorithm(a, b, count);
	else if (flags.strategy == COMPLEX)
		complex_algorithm(a, b, count);
	else
		adaptive(a, b, disorder, count);
	if (flags.bench)
		bench(disorder, count, flags);
}

/* Program entry point. Initializes structures, parses flags,
** validates and builds stack a, executes the algorithm, and frees memory.
** With no arguments it does nothing. On error it prints "Error" to stderr and 
exits.
*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_count	count;
	t_flags	flags;
	int		i;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	if (argc == 1)
		return (0);
	init_all(&a, &b, &count);
	i = parse_flags(argv, &flags);
	if (i == -1)
		error_exit(&a, &b);
	if (!validate_numbers(argc, argv, i, &a))
		error_exit(&a, &b);
	execute_algorithms(&a, &b, &count, flags);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
