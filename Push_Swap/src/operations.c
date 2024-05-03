/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:28:36 by msinke            #+#    #+#             */
/*   Updated: 2024/05/03 16:20:12 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
			Do nothing if there is only one or no elements
ss : sa and sb at the same time. Do you have to fork or is calling it twice sufficent?
*/

void	ft_swap(t_node **stackA)
{
	t_node	*first;
	t_node	*second;

	if (*stackA != NULL && (*stackA)->next != NULL)
	{
		first = *stackA;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stackA = second;
	}
}
// 			a -> b -> c -> d -> NULL
// NULL < - a <- b <- c <- d


/*
pa (push a): take the first element at the top of b 
			and put it at the top of a
			do nothing if b is empty
*/
void	ft_pa(t_node **stackA, t_node **stackB)
{
	t_node	*temp;

	if (*stackB != NULL)
	{
		temp = *stackB;
		*stackB = (*stackB)->next;
		temp->next = *stackA;
		*stackA = temp;
	}
}
/*
pb (push b): Take the first element at the top of a
			and put it at the top of b
			do nothing if a is empty
*/

void	ft_pb(t_node **stackA, t_node **stackB)
{
	t_node	*temp;

	if (*stackA != NULL)
	{
		temp = *stackA; // Top element of stackA
		*stackA = (*stackA)->next; // Remove top element from stackA
		temp->next = *stackB; // Push it onto stackB
		*stackB = temp; //Update top of stackB
	}
}

/*
ra (rotate a): Sihft up all elements of stack a by 1. 
				The first element becomes the last one.
rr ; ra and rb at the same time (just call the function twice?)
*/

void	ft_r(t_node **stackA)
{
	t_node *temp;
	t_node	*last;
	t_node	*second_last;

	if (*stackA != NULL && (*stackA)->next != NULL)
	{
		temp = *stackA; //a
		*stackA = (*stackA)->next; //b
		last = *stackA; //b
		while (last->next != NULL)
			last = last->next; //d
		last->next = temp; //d -> a
		temp->next = NULL; //a -> NULL

		last = *stackA;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last->next = NULL;
			last->next = *stackA;
			*stackA = last;
		}

	}
}

// a -> b -> c -> d -> NULL

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one
*/

void	ft_rr(t_node **stackA)
{
	t_node	*temp;
	t_node	*last;
	t_node	*first;

	if (*stackA != NULL && (*stackA)->next != NULL)
	{
		// een na laatste -> next moet naar NULL pointen
		//de laastste moet naar de eerste pointen
		first = *stackA; // 4
		temp = *stackA;	//4
		*stackA = (*stackA)->next; //9
		last = *stackA; //9
		while (last->next != NULL) // while last->next doesn't point to NULL
			last = last->next; //last becomes last->next, so lasts points to d // 5
		while (temp->next != last) // while temp->next doens't point to last
			temp = temp->next; //temp points to c
		// last points to be, temp points to c, b connext with c
		temp->next = NULL;
		last->next = first; //move d->a
		// c -> NULL
		// d -> a
	}
}

// 4 -> 9 -> 6 -> 5
