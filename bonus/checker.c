/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:33:21 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/10 21:29:10 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_numbers(char **numbers)
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

static void	free_all(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
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
