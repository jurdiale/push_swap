/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:45:48 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/11 13:41:40 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include "bonus/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_flags
{
	int	strategy;
	int	bench;
}	t_flags;

typedef struct s_count /* estructura para contar operaciones --bench*/
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_count;

# define SIMPLE		0
# define MEDIUM		1
# define COMPLEX	2
# define ADAPTATIVE	3

void	sa(t_stack **a, int print, t_count *count);
void	sb(t_stack **b, int print, t_count *count);
void	ss(t_stack **a, t_stack **b, int print, t_count *count);
void	pb(t_stack **a, t_stack **b, int print, t_count *count);
void	pa(t_stack **a, t_stack **b, int print, t_count *count);
void	ra(t_stack **a, int print, t_count *count);
void	rb(t_stack **b, int print, t_count *count);
void	rr(t_stack **a, t_stack **b, int print, t_count *count);
void	rra(t_stack **a, int print, t_count *count);
void	rrb(t_stack **b, int print, t_count *count);
void	rrr(t_stack **a, t_stack **b, int print, t_count *count);

long	ft_atol(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

int		is_valid(char *str);
int		there_are_duplicates(t_stack *a);
void	normalize(t_stack *a);
float	compute_disorder(t_stack *a);

void	error_exit(t_stack **a, t_stack **b);

void	free_stack(t_stack **a);
int		push_stack(t_stack **a, int value);
int		meet_destination(t_stack *a, int index);
int		calcule_cost(t_stack *a, t_stack *b, int index_b);
int		meet_better(t_stack *a, t_stack *b);
void	rotate_both(t_stack **a, t_stack **b, int better, t_count *count);
void	rotate_minimum_b(t_stack **b, t_count *count);
void	rotate_min_a(t_stack **a, t_count *count);
int		stack_size(t_stack *a);
int		position(t_stack *stack, int index);
int		meet_max(t_stack *a);
int		meet_minimum(t_stack *a);
int		max(int a, int b);
void	order_3(t_stack **a, t_count *count);
void	free_numbers(char **numbers);
void	free_all(t_stack **a, t_stack **b);
void	build_stack(t_stack **a, t_stack **b, char **numbers);
int		parse_flags(char **argv, t_flags *flag);

void	order_2(t_stack **a, t_count *count);
void	lineal_algorithm(t_stack **a, t_count *count);
void	complex_algorithm(t_stack **a, t_stack **b, t_count *count);
void	simple_algorithm(t_stack **a, t_stack **b, t_count *count);
void	medium_algorithm(t_stack **a, t_stack **b, t_count *count);
void	adaptative(t_stack **a, t_stack **b, float disorder, t_count *count);
void	bench(float disorder, t_count *count, t_flags flag);
void	phase_2(t_stack **a, t_stack **b, t_count *count);
void	phase_3(t_stack **a, t_count *count);

#endif