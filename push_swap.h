/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurdiale <jurdiale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:45:48 by jurdiale          #+#    #+#             */
/*   Updated: 2026/07/29 12:28:11 by jurdiale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

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

int		is_valid(char *str);
int 	there_are_duplicates(t_stack *a);
void    normalize(t_stack *a);
float	compute_disorder(t_stack *a)

void    error_exit(t_stack **a, t_stack **b);

void    free_stack(t_stack **a);
int		push_stack(t_stack **a, int value);

#endif