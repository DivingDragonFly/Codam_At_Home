/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:28:36 by msinke            #+#    #+#             */
/*   Updated: 2024/05/29 11:29:34 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
			Do nothing if there is only one or no elements
ss : sa and sb at the same time. Do you have to fork or is calling it twice sufficent?
*/
//swap first two elements

void	sa(t_node **stackA)
{
	t_node	*nodeA;
	t_node	*nodeB;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	nodeA = *stackA;
	nodeB = (*stackA)->next;
	if (nodeB->next != NULL)
		nodeB->next->previous = nodeA;
	nodeA->next = nodeB->next;
	nodeB->next = nodeA;
	nodeA->previous = nodeB;
	nodeB->previous = NULL;
	*stackA = nodeB;
	// printf("sa\n")
}

void	sb(t_node **stackB)
{
	t_node	*nodeA;
	t_node	*nodeB;

	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	nodeA = *stackB;
	nodeB = (*stackB)->next;
	if (nodeB->next != NULL)
		nodeB->next->previous = nodeA;
	nodeA->next = nodeB->next;
	nodeB->next = nodeA;
	nodeA->previous = nodeB;
	nodeB->previous = NULL;
	*stackB = nodeB;
	// printf("sb\n");
}


/*
pa (push a): take the first element at the top of b 
			and put it at the top of a
			do nothing if b is empty
*/



void	pa(t_node **source, t_node **dest)
{
	t_node	*new_head;
	t_node	*nodeA;

	if (*source == NULL)
		return ;
	new_head = *source;
	nodeA = *dest;
	*source = (*source)->next;
	if (new_head->next != NULL)
		new_head->next->previous = NULL;
	new_head->next = nodeA;
	if (nodeA != NULL)
		nodeA->previous = new_head;
	*dest = new_head;
	// printf("pa\n");
}

void	pb(t_node **source, t_node **dest)
{
	t_node	*new_head;
	t_node	*nodeB;

	if (*source == NULL)
		return ;
	new_head = *source;
	nodeB = *dest;
	*source = (*source)->next;
	if (new_head->next != NULL)
		new_head->next->previous = NULL;
	new_head->next = nodeB;
	if (nodeB != NULL)
		nodeB->previous = new_head;
	*dest = new_head;
	// printf("pb\n");
}

// void	ft_push(t_node **stackA, t_node **stackB)
// {
// 	t_node	*nodeB;
// 	t_node	*nodeA;

// 	if (*stackB == NULL)
// 		return ;
// 	nodeB = *stackB;
// 	nodeA = *stackA;
// 	*stackB = (*stackB)->next;
// 	if (nodeB->next != NULL)
// 		nodeB->next->previous = NULL;
// 	nodeB->next = nodeA;
// 	if (nodeA != NULL)
// 		nodeA->previous = nodeB;
// 	*stackA = nodeB;
// }

/*
ra (rotate a): Sihft up all elements of stack a by 1. 
				The first element becomes the last one.
*/

void	ra(t_node **stackA)
{
	t_node	*last;
	t_node	*tail;
	
	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	last = *stackA;
	while (last->next != NULL)
		last = last->next;
	tail = *stackA;
	*stackA = (*stackA)->next;
	(*stackA)->previous = NULL;
	last->next = tail;
	tail->previous = last;
	tail->next = NULL;
	// printf("ra\n");
}

void	rb(t_node **stackB)
{
	t_node	*last;
	t_node	*tail;
	
	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	last = *stackB;
	while (last->next != NULL)
		last = last->next;
	tail = *stackB;
	*stackB = (*stackB)->next;
	(*stackB)->previous = NULL;
	last->next = tail;
	tail->previous = last;
	tail->next = NULL;
	// printf("rb\n");
}

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one
*/


void	rra(t_node **stackA)
{
	t_node	*head;
	t_node	*first;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	head = *stackA;
	while (head->next != NULL)
		head = head->next;
	first = *stackA;
	*stackA = head;
	head->previous->next = NULL;
	head->next = first;
	head->previous = NULL;
	first->previous = head;
	// printf("rra\n");
}

void	rrb(t_node	**stackB)
{
	t_node	*head;
	t_node	*first;
	
	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	head = *stackB;
	while (head->next != NULL)
		head = head->next;
	first = *stackB;
	*stackB = head;
	head->previous->next = NULL;
	head->next = first;
	head->previous = NULL;
	first->previous = head;
	// printf("rrb\n");
}
