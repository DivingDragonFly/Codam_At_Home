/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stackA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:32:53 by milousinke        #+#    #+#             */
/*   Updated: 2024/05/29 12:02:51 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	recursive_sort(t_node **stackA, t_node **stackB, int count)
// {
// 	t_node	nodeA;

// 	nodeA = *stackA;
// 	while (count > 0)
// 	{
		
		
// 	}
// }

void printStack(t_node **head)
{
    t_node *current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void    descending_sort_three_values(t_node **stackB)
{
    t_node  *first;
    t_node  *second;
    t_node  *third;

    first = *stackB;
    second = (*stackB)->next;
    third = (*stackB)->next->next;
    if (descending_check(stackB))
        return ;
    if (first->data < second->data)
    {
        if (second->data > third->data)
        {
            if (first->data < third->data)
                rrb(stackB);
            else
                sb(stackB);
        }
        else
        {
            sb(stackB);
            rrb(stackB);
        }
    }
    else
    {
        if (third->data > first->data)
            rrb(stackB);
        else
        {
            sb(stackB);
            rb(stackB);
        }
    }
}

void    ascending_three_values(t_node **stackA)
{
    t_node  *first;
    t_node  *second;
    t_node  *third;

    first = *stackA;
    second = (*stackA)->next;
    third = (*stackA)->next->next;
    if (ascending_check(stackA))
        return ;
    if (first->data < second->data)
    {
        if (third->data < first->data)
            rra(stackA);
        else
        {
            rra(stackA);
            sa(stackA);
        }
    }
    else
    {
        if (third->data > first->data)
            sa(stackA);
        else if (second->data < third->data)
            rra(stackA);
        else
        {
            sa(stackA);
            rra(stackA);
        }
    }
}

void	second_sorting(t_node **stackA, t_node **stackB)
{
	t_node	*pivot;
	t_node	*nodeB;
	// int		count;

	if (!*stackB || !(*stackB)->next)
		return ;
	// count = 0;
	pivot = whole_stack_pivot_choice(stackB);
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
		if (nodeB->data > pivot->data)
		{
			pa(stackB, stackA);
			// count++;
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

// void    back_iteration_stackA(t_node **stackA, t_node **stackB, int count)
// {
//     t_node  *pivot;
//     // I immediately wanna check the count
//     // choose pivot from count elements
//     pivot = elements_pivot_choice(stackA, count);
    
// }

// void    iterate_sort_stackaA(t_node **stackA, t_node **stackB)
// {
//     t_node  *pivot;
//     t_node  *nodeA;
//     int     count;

//     if (!*stackA || !(*stackA)->next)
//         return ;
//     count = 0;
//     pivot = whole_stack_pivot_choice(stackA);
//     if (pivot == NULL)
//         return ;
//     //get pivot at end of stackA
//     while (*stackA != pivot)
//         ra(stackA);
//     ra(stackA);

//     nodeA = *stackA;
//     while (nodeA != pivot)
//     {
//         nodeA = *stackA;
//         if (nodeA->data < pivot->data)
//         {
//             pb(stackA, stackB);
//             count++;
//         }
//         else
//             ra(stackA);
//     }
//     iterate_sort_stackA(stackA, stackB);
//     // sort the other sequences using pivot
//     //first sort what's left of  stackA
//     // then sort from stackA -> stackB biggest first
//     // if (count > 3)
//     //     back_iteration_stackA(stackA, stackB, count);
//     // else
//     //     sort_three_values(stackA);
// }

// initial partition puts everything below pivot in stackB
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
    pivot = whole_stack_pivot_choice(stackA);
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

