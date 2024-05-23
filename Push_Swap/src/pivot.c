/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:57:05 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/23 19:15:09 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_median(int x, int y, int z)
{
    if (x > y)
    {
        if (x < z)
            return (x);
        else if (y > z)
            return (y);
        else
            return (z);
    }
    else
    {
        if (y < z)
            return (y);
        else if (x > z)
            return (x);
        else
            return (z);
    }
}

t_node  *ft_node_value(t_node *first, t_node *middle, t_node *last, int value)
{
    if (first->data == count)
        return (first);
    else if (middle->data == count)
        return (middle);
    else if (last->data == count)
        return (last);
    else
        return (NULL);
}

t_node  *pivot_choice(t_node **stackA)
{
    t_node  *middle;
    t_node  *first;
    t_node  *last;
    int     count;

    count = 0;
    first = *stackA;
    last = first;
    while (last->next)
    {
        last = last->next;
        count++;
    }
    count /= 2;
    middle = last;
    while (count > 0)
    {
        middle = middle->previous;
        count--;
    }
    count = find_median(first->data, middle->data, last->data);
    return (ft_node_value(first, middle, last, count));
}
