/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:57:05 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/24 17:00:21 by msinke           ###   ########.fr       */
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
    if (first->data == value)
        return (first);
    else if (middle->data == value)
        return (middle);
    else if (last->data == value)
        return (last);
    else
        return (NULL);
}

t_node  *pivot_choice(t_node **stackA)
{
    t_node  *middle;
    t_node  *first;
    t_node  *last;
	t_node	*pivot;
    int     count;
	int		median_value;

	if (!*stackA || !(*stackA)->next || !(*stackA)->next->next)
		return (NULL);
    count = 0;
    first = *stackA;
    last = first;
    while (last->next)
    {
        last = last->next;
        count++;
    }
	if (count <= 2)	
		return (NULL);
    count /= 2;
    middle = last;
    while (count > 0)
    {
        middle = middle->previous;
        count--;
    }
    median_value = find_median(first->data, middle->data, last->data);
	pivot = ft_node_value(first, middle, last, median_value);
    return (pivot);
}
