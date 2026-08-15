/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 20:00:20 by Jose              #+#    #+#             */
/*   Updated: 2026/08/12 17:06:15 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the array of strings containing the numbers to process.
** If there is a single argument (argc == i+1), uses ft_split to separate it 
by spaces.
** If there are multiple arguments, returns argv+i directly (no malloc).
*/

static char	**get_numbers(int argc, char **argv, int i)
{
	if (argc == i + 1)
		return (ft_split(argv[i], ' '));
	return (argv + i);
}

/* Frees the array of numbers if it was created by ft_split (split=1).
** Does nothing if split=0 because in that case numbers points to argv.
*/

static void	free_input(char **numbers, int split)
{
	if (split && numbers)
		free_numbers(numbers);
}

/* Frees the input and returns 0 (error).
** Helper to centralize the free+return‑error pattern in validate_numbers.
*/

static int	free_input_error(char **numbers, int split)
{
	free_input(numbers, split);
	return (0);
}

/* Iterates through the array of strings from right to left and builds stack a.
** The reverse traversal ensures that the first number in argv ends up at the 
top of a.
** Validates each string with is_valid and inserts it with push_stack.
** Returns 0 if any string is invalid or malloc fails, 1 if everything is 
correct.
*/

static int	add_numbers(char **numbers, t_stack **a)
{
	int	j;

	j = 0;
	while (numbers[j])
		j++;
	while (--j >= 0)
	{
		if (!is_valid(numbers[j])
			|| !push_stack(a, (int)ft_atol(numbers[j])))
			return (0);
	}
	return (1);
}

/* Builds stack a from argv[i..argc-1] or from a single string.
** Validates duplicates, normalizes indices, and frees temporary memory.
** Returns 1 if everything is correct, 0 if any error occurs.
*/

int	validate_numbers(int argc, char **argv, int i, t_stack **a)
{
	char	**numbers;
	int		split;

	if (argc <= i)
		return (0);
	split = (argc == i + 1);
	numbers = get_numbers(argc, argv, i);
	if (!numbers || !numbers[0])
		return (free_input_error(numbers, split));
	if (!add_numbers(numbers, a))
		return (free_input_error(numbers, split));
	if (there_are_duplicates(*a))
		return (free_input_error(numbers, split));
	normalize(*a);
	free_input(numbers, split);
	return (1);
}
