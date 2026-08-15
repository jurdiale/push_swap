/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:29:04 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/15 11:44:57 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Prints an integer to any file descriptor using write.
** Recursive: extracts digits from right to left.
** Used by bench to write numbers to stderr (fd=2).
*/

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

/* Writes to stderr the total number of operations and the counters for 
sa/sb/ss/pa/pb.
*/

static void	w_operations1(t_count *count)
{
	write(2, "Total Operations: ", 18);
	ft_putnbr_fd(count->total, 2);
	write(2, "\n", 1);
	write(2, "sa: ", 4);
	ft_putnbr_fd(count->sa, 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(count->sb, 2);
	write(2, " ss: ", 5);
	ft_putnbr_fd(count->ss, 2);
	write(2, "\n", 1);
	write(2, "pa: ", 4);
	ft_putnbr_fd(count->pa, 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(count->pb, 2);
	write(2, "\n", 1);
}

/* Writes to stderr the counters for ra/rb/rr/rra/rrb/rrr.
*/

static void	w_operations2(t_count *count)
{
	write(2, "ra: ", 4);
	ft_putnbr_fd(count->ra, 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(count->rb, 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(count->rr, 2);
	write(2, "\n", 1);
	write(2, "rra: ", 5);
	ft_putnbr_fd(count->rra, 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(count->rrb, 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(count->rrr, 2);
	write(2, "\n", 1);
}

static void	print_adaptive(float disorder)
{
	if (disorder < 0.2)
		write(2, "Strategy: Adaptive / O(n²)\n", 29);
	else if (disorder >= 0.2 && disorder < 0.5)
		write(2, "Strategy: Adaptive / O(n*raíz(n))\n", 36);
	else
		write(2, "Strategy: Adaptive / O(n*log(n))\n", 33);
}

/* Prints the metrics of the --bench mode to stderr after sorting.
** Shows: disorder index (%), name and complexity of the algorithm used,
** total number of operations, and breakdown by type (sa, sb, ..., rrr).
*/

void	bench(float disorder, t_count *count, t_flags flag)
{
	int	integer;
	int	decimal;

	integer = (int)(disorder * 100);
	decimal = (int)(((disorder * 100) - integer) * 100);
	write(2, "Disorder: ", 10);
	ft_putnbr_fd(integer, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%\n", 2);
	if (flag.strategy == SIMPLE)
		write(2, "Strategy: Simple O(n^2)\n", 25);
	if (flag.strategy == MEDIUM)
		write(2, "Strategy: Medium O(n*sqrt(n))\n", 30);
	if (flag.strategy == COMPLEX)
		write(2, "Strategy: Complex O(n*log(n))\n", 30);
	if (flag.strategy == ADAPTIVE)
		print_adaptive(disorder);
	w_operations1(count);
	w_operations2(count);
}
