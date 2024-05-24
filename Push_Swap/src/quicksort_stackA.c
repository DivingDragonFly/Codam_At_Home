/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stackA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:32:53 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/24 17:09:01 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_sort(t_node **stackA, t_node **stackB, int count)
{
	t_node	nodeA;

	nodeA = *stackA;
	while (count > 0)
	{
		
		
	}
}

void printStack(t_node **head)
{
    t_node *current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void	second_sorting(t_node **stackA, t_node **stackB)
{
	t_node	*pivot;
	t_node	*nodeB;
	int		count;

	if (!*stackB || !(*stackB)->next)
		return ;
	count = 0;
	pivot = pivot_choice(stackB);
	if (pivot == NULL)
		return ;
	printf("pivot: %d\n", pivot->data);
	while (*stackB != pivot)
		rb(stackB);
	rb(stackB);
	nodeB = *stackB;
	while (nodeB != pivot)
	{
		nodeB = *stackB;
		if (nodeB->data < pivot->data)
		{
			pa(stackB, stackA);
			count++;
		}
		else
			rb(stackB);
	}
	printf("stackA:\n");
	printStack(stackA);
	printf("stackB:\n");
	printStack(stackB);
	second_sorting(stackA, stackB);
	// recursive_sort(stackA, stackB, count);
}

void    initial_partition(t_node **stackA, t_node **stackB)
{
    t_node  *pivot;
    t_node  *nodeA;
    int     count;
	int		operations;

	count = 0;
    nodeA = *stackA;
	//Count nodes in stackA
    while (nodeA)
    {
        nodeA = nodeA->next;
        count++;
    }
    // find first pivot
    pivot = pivot_choice(stackA);
    // make sure pivot is in middle
    nodeA = *stackA;
	//Temporarily move pivot to the bottom of stackA
	//I could use count maybe, to reduce inefficiency
    // if (nodeA == pivot)
    // {
    //     nodeA = nodeA->next;
    //     ra(stackA);
    // }
	while (*stackA != pivot)
		ra(stackA);
    ra(stackA);
	// Partition around the pivot
	operations = count - 1;
    while (operations-- > 0)
    {
        nodeA = *stackA;
        if (nodeA->data > pivot->data)
            ra(stackA);
        else
            pb(stackA, stackB);
    }
	second_sorting(stackA, stackB);
    

}