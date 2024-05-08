/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:28:36 by msinke            #+#    #+#             */
/*   Updated: 2024/05/08 17:15:00 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
			Do nothing if there is only one or no elements
ss : sa and sb at the same time. Do you have to fork or is calling it twice sufficent?
*/
//swap first two elements
void	ft_swap(t_node **stackA)
{
	t_node	*first;
	t_node	*second;

	first = *stackA; //*stackA is hier head van linked list
	second = first->next; //pointer to struct, points to value of second element linked list
	first->next = second->next; // the adress stored in first->next (adress second element)
	// becomes the adress stored in second->next (adress of third element)
	second->next = first; //makes Node B points to Node A
	first->previous = second; //swap the pointer from 'NULL' to 'Node B'
	if (first->next != NULL) 
		first->next->previous = first; //update 'Node C' to previous point to 'Node A'
	second->previous = NULL; //update pointer to NULL since it's head of list
	*stackA = second; //update head of list to second node
}


/*
pa (push a): take the first element at the top of b 
			and put it at the top of a
			do nothing if b is empty
*/

void	ft_push(t_node **stackA, t_node **stackB)
{
	t_node	*nodeB;
	t_node	*nodeA;

	if (*stackB == NULL)
		return ;
	nodeB = *stackB;
	nodeA = *stackA;
	*stackB = (*stackB)->next;
	if (nodeB->next != NULL)
		nodeB->next->previous = NULL;
	nodeB->next = nodeA;
	if (nodeA != NULL)
		nodeA->previous = nodeB;
	*stackA = nodeB;
}

/*
ra (rotate a): Sihft up all elements of stack a by 1. 
				The first element becomes the last one.
*/

void	ft_rotate(t_node **stackA)
{
	t_node	*first;
	t_node	*last;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	last = *stackA;
	while (last->next != NULL)
		last = last->next;
	first = *stackA;
	*stackA = first->next;
	(*stackA)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one
*/


void	ft_reverse_rotate(t_node **stackA)
{
	t_node	*first;
	t_node	*last;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	last = *stackA;
	while (last->next != NULL)
		last = last->next;
	first = *stackA;
	*stackA = last;
	last->previous->next = NULL;
	last->next = first;
	first->previous = last;
	last->previous = NULL;
}
