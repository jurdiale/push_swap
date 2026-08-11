/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:29:04 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/11 13:00:01 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	bench(float disorder, t_count *count, t_flags flag)
{
	int	integer;
	int	decimal;

	integer = (int)(disorder);
	decimal = (int)((disorder - integer) * 100);
	write(2, "Disorder: ", 10);
	ft_putnbr_fd(integer, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%\n", 2);
	if (flag.strategy == SIMPLE)
		write(2, "Strategy: Simple O(n^2)\n", 24);
	if (flag.strategy == MEDIUM)
		write(2, "Strategy: Medium O(n*sqrt(n))\n", 30);
	if (flag.strategy == COMPLEX)
		write(2, "Strategy: Complex O(n*log(n))\n", 30);
	if (flag.strategy == ADAPTATIVE)
		write(2, "Strategy: Adaptive\n", 19);
	w_operations1(count);
	w_operations2(count);
}
