/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:45:20 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/03 18:02:25 by msinke           ###   ########.fr       */
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

  // find smallest int in linked list
// 4 -> 5 -> 6 -> 9 -> 23 -> 34


void	sort_a_b(t_node **stackA, t_node **stackB)
{
	t_node	*current;
	t_node	*head;

	if (stackA == NULL || *stackA == NULL || (*stackA)->next == NULL)
		return ;

	while (*stackA != NULL && (*stackA)->next != NULL)
	{
		head = *stackA;
		current = head->next;
		if (head->data > current->data)
			ft_swap(stackA);
		ft_pb(stackA, stackB);
	}

}

void	sort_b_a(t_node **stackA, t_node **stackB)
{
	t_node	*current;
	t_node	*head;

	if (stackB == NULL || *stackB == NULL || (*stackB)->next == NULL)
		return ;

	while (*stackB != NULL && (*stackB)->next != NULL)
	{
		head = *stackB;
		current = head->next;
		if (head->data < current->data)
			ft_swap(stackB);
		ft_pa(stackA, stackB);
	}
}

//for stackB it needs to be descending, cause then
//when moving to stackA it will be ascending
int	ascending_check(t_node **stackA)
{
	t_node	*current;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return (true);
	current = *stackA;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}

int	descending_check(t_node **stackB)
{
	t_node	*current;

	if (*stackB == NULL || (*stackB)->next == NULL)
		return (true);
	current = *stackB;
	while (current->next != NULL)
	{
		if (current->data < current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}

void	sort(t_node **stackA, t_node **stackB)
{
	if (ascending_check(stackA) && descending_check(stackB))
		return ;
	while (!(ascending_check(stackA)) || !(descending_check(stackB)))
	{
		if (*stackA != NULL && (*stackA)->next != NULL)
			sort_a_b(stackA, stackB);
		else if (*stackB != NULL && (*stackB)->next != NULL)
			sort_b_a(stackA, stackB);
	}
}
