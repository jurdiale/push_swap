/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:07:07 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:36:02 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Calculates how many bits are needed for the maximum index value (0 to size-1)
** Returns the first n such that 2^n >= size.
** For 100 elements it returns 7 (2^7 = 128 >= 100). For 500 it returns 9.
*/

static int	calculate_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

/* O(n*log(n)) algorithm: LSD radix sort adapted for stacks.
** For each bit (from least to most significant): iterate through all size
elements in a
** If the current bit of the index is 0 -> pb (goes to b).
If it is 1 -> ra (stays in a)
** At the end of each pass, push everything from b back to a with pa.
Ensures correct ordering.
*/

void	complex_algorithm(t_stack **a, t_stack **b, t_count *count)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = stack_size(*a);
	bits = calculate_bits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, 1, count);
			else
				pb(a, b, 1, count);
			j++;
		}
		while ((*b != NULL))
			pa(a, b, 1, count);
		i++;
	}
}
