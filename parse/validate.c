/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:22:19 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/11 03:56:52 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid(char *str)
{
	long int	n;
	char		*temp;

	temp = str;
	if (*str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	n = ft_atol(temp);
	if (n > INT_MAX)
		return (0);
	if (n < INT_MIN)
		return (0);
	return (1);
}

int	there_are_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*temp;

	current = a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->value == current->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
