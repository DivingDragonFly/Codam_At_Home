/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:45:20 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/02 20:01:37 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Selection sort
    The algorithm repeatedly selects the smallest (or largest)
    element from the unsorted portion of the list and swaps it
    with the first element of the unsorted part. This process is repeated
    for the remaining unsorted portion until the entire
    list is sorted.

swap first two elements of stack
take first element of stackB and put it at the top of stackA
Shift up all elements of stack a by 1 
    first element becomes the last one
Shift down all elements of stack a by 1
    the last element becomes the first one

*/
// ascending order, smallest to largest
// 6 -> 9 -> 5 -> 4 -> 23 -> 34

/*
if stackA > stackA->next
push b (element top a goes to top b)
what if I create a while loop, that pushes 
*/

// 4 -> 5 -> 6 -> 9 -> 23 -> 34

t_node    *first_pass(t_node *stackA)
{
    t_node  *current;
    t_node  *head;

    if (stackA == NULL)
        return (NULL);
    head = stackA;
    current = stackA->next;
    while (current != NULL)
    {
        if (current->data < head->data)
            head = current;
        current = current->next;
    }
    return (head);
}

  // find smallest int in linked list

