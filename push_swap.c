/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:35:45 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/11 17:27:28 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_all(t_stack **a, t_stack **b, t_count *count)
{
	*a = NULL;
	*b = NULL;
	ft_memset(count, 0, sizeof(t_count));
}

int	validate_numbers(int argc, char **argv, int i, t_stack **a)
{
	char	**numbers;
	int		j;

	if (argc == i + 1)
		numbers = ft_split(argv[i], ' ');
	else
		numbers = argv + i;
	j = 0;
	while (numbers[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!is_valid(numbers[j]) || !push_stack(a, (int)ft_atol(numbers[j])))
			return (0);
		j--;
	}
	if (there_are_duplicates(*a))
		return (0);
	normalize(*a);
	return (1);
}

void	execute_algorithms(t_stack **a, t_stack **b, t_count *count,
	t_flags flags)
{
	int		size;
	float	disorder;

	disorder = compute_disorder(*a);
	size = stack_size(*a);
	if (size == 2)
		order_2(a, count);
	else if (size == 3)
		order_3(a, count);
	else if (size > 3)
	{
		if (flags.strategy == SIMPLE)
			simple_algorithm(a, b, count);
		else if (flags.strategy == MEDIUM)
			medium_algorithm(a, b, count);
		else if (flags.strategy == COMPLEX)
			complex_algorithm(a, b, count);
		else
			adaptative(a, b, disorder, count);
	}
	if (flags.bench)
		bench(disorder, count, flags);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_count	count;
	t_flags	flags;
	int		i;

	flags.strategy = ADAPTATIVE;
	flags.bench = 0;
	if (argc == 1)
		return (0);
	init_all(&a, &b, &count);
	i = parse_flags(argv, &flags);
	if (i == -1)
		return (0);
	if (!validate_numbers(argc, argv, i, &a))
		error_exit(&a, &b);
	execute_algorithms(&a, &b, &count, flags);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
