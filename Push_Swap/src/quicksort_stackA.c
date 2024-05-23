/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stackA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:32:53 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/23 19:34:05 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    quicksort_stackA(t_node **stackA)
{
    t_node  *pivot;
    t_node  *nodeA;
    t_node  *nodeB;
    int     count;

    nodeA = *stackA;
    while (stackA)
    {
        nodeA = nodeA->next;
        count++;
    }
    // find first pivot
    if (count <= 3)
    {
        //sort using other algorithm
        //end this function
    }
    pivot = pivot_choice(stackA);
    // make sure pivot is in middle
    nodeA = *stackA;
    if (nodeA == pivot)
    {
        nodeA = nodeA->next;
        ra(stackA);
    }
    // if pivot is middle one, I gotta fix logic
    while (nodeA != pivot)
    {
        if (nodeA->data > pivot->data)
            ra(stackA);
        else if (nodeA->data < pivot->data)
            sa(stackA);
        nodeA = *stackA;
    }
        

    // then i need to sort everything above/below pivot if cost aren't high

}