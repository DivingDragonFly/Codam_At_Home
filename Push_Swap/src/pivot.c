/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:57:05 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/28 20:27:11 by milousinke       ###   ########.fr       */
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

t_node  *whole_stack_pivot_choice(t_node **stackA)
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

t_node  *elements_pivot_choice(t_node **stackA, int count)
{
    t_node  *first;
    t_node  *last;
    t_node  *middle;
    t_node  *pivot;
    int     i;

    if (!*stackA || !(*stackA)->next || !(*stackA)->next->next)
        return (NULL);
    first = *stackA;
    middle = *stackA;
    last = *stackA;
    i = count;
    while (i > 0)
    {
        last = last->next;
        i--;
    }
    i = count/2;
    while (i > 0)
    {
        middle = middle->next;
        i--;
    }
    i = find_median(first->data, middle->data, last->data);
    pivot = ft_node_value(first, middle, last, i);
    return (pivot);
}
