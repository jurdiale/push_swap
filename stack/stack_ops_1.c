/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jose <jurdiale@student.42malaga.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:49:11 by Jose              #+#    #+#             */
/*   Updated: 2026/08/02 18:49:11 by Jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int meet_destination(t_stack *a, int index)
{
    int destination;
    t_stack *temp;

    destination = meet_max(a);
    temp = a;
    while (temp != NULL)
        {
            if (temp->index > index && temp->index < destination)
                destination = temp->index;
            temp = temp->next;
        }
    return destination;
}

int calcule_cost(t_stack *a, t_stack *b, int index_b)
{
    int pos_b;
    int destination;
    int pos_a;
    int size_a;
    int size_b;

    pos_b = position(b, index_b);
    destination = meet_destination(a, index_b);
    pos_a = position(a, destination);
    size_a = stack_size(a);
    size_b = stack_size(b);

    if ((pos_b <= (size_b / 2)) && (pos_a <= (size_a / 2)))
        return max(pos_b, pos_a);
    if ((pos_b > (size_b / 2)) && (pos_a > (size_a / 2)))
        return max(size_b - pos_b, size_a - pos_a);
    if ((pos_b <= (size_b / 2)) && (pos_a > (size_a / 2)))
        return (pos_b + (size_a - pos_a));
    if ((pos_b > (size_b / 2)) && (pos_a <= (size_a / 2)))
        return ((size_b - pos_b) + pos_a);
}

int meet_better(t_stack *a, t_stack *b)
{
    int better;
    int better_index;
    int cost;
    t_stack *temp;

    better = INT_MAX;
    better_index = b->index;
    temp = b;
    while (temp != NULL)
    {
        cost = calcule_cost(a, b, temp->index);
        if (cost < better)
        {
            better = cost;
            better_index = temp->index;
        }
        temp = temp->next;
    }
    return (better_index);
}

void    rotate_both(t_stack **a, t_stack **b, int better, t_count *count)
{
    int pos_b;
    int destination;
    int pos_a;
    int size_a;
    int size_b;

    pos_b = position(*b, better);
    destination = meet_destination(*a, better);
    pos_a = (*a, destination);
    size_a = stack_size(*a);
    size_b = stack_size(*b);

    if ((pos_b <= (size_b / 2)) && (pos_a <= (size_a / 2)))
        {
            while ((pos_b > 0) && (pos_a > 0))
            {
                
            }
        }
}