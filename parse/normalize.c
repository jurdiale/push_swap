/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:36:09 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/09 21:10:48 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    normalize(t_stack *a)
{
    t_stack *current;
    t_stack *temp;
    int		i;

    current = a;
    while (current != NULL)
    {
        i = 0;
        temp = a;
        while (temp != NULL)
        {
            if (temp->value < current->value)
                i++;
            temp = temp->next;
        }
	current->index = i;
	current = current->next;	
    }
}

float	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	t_stack	*current;
	t_stack	*temp;

	current = a;
	mistakes = 0;
	total_pairs = 0;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			total_pairs++;
			if (current->index > temp->index)
				mistakes++;
			temp = temp->next;
		}
		current = current->next;
	}	
	return ((float)mistakes / (float)total_pairs);
}
