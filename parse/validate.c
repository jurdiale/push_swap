/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:22:19 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 16:55:13 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Checks that str represents a valid integer within the INT_MIN..INT_MAX range.
** Accepts an optional + or - sign at the beginning. Rejects empty strings,
** non‑numeric input, and overflow. Returns 1 if valid, 0 otherwise.
*/

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

/* Compares all pairs of nodes looking for repeated values.
** Returns 1 if duplicates are found, 0 if all values are distinct.
*/

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
