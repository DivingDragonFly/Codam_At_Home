/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:24:00 by msinke            #+#    #+#             */
/*   Updated: 2024/05/14 17:02:22 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Head will be pivot
// 10 -> 80 -> 30 -> 90 -> 40 -> 50 -> 70
 0 -> 6 -> 1 ->
 
 a 40 -> 90 -> 30 -> 80 -> 10
 b 
 a 90 -> 40 -> 30 -> 80 -> 10
 b 
 a 40 -> 30 -> 80 -> 10
 b 90
 a 30 -> 40 -> 80 -> 10
 b 90
 a 40 -> 80 -> 10 -> 30
 b 90
 a 80 -> 40 -> 10 -> 30
 b 90
 a 40 -> 10 -> 30
 b 80 -> 90
 a 10 -> 40 -> 30
 b 80 -> 90
 a 40 -> 30 -> 10
 b 80 -> 90
 40 -> 30 -> 80 -> 10

*/

// if stackA only has one element you shouldn't even call quicksort
void	first_pivot(t_node **stackA, t_node **stackB)
{
	t_node	*pivot;
	t_node	*current;
	t_node	*next;
	
	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	// still need to check pivot choice
	// looping through pivots isn't logical yet
	printf("pivot while loop\n");
	while (*stackA != NULL)
	{
		pivot = *stackA;
		rotate_a(stackA);
		current = *stackA;
		while (current != pivot)
		{
			next = current->next;
			if (current->data < pivot->data)
				ft_push_a(stackA, stackB);
			else
				rotate_a(stackA);
			current = next;
		}
		ft_push_a(stackA, stackB);
		print_stack(*stackA, "first pivot stackA");
    	print_stack(*stackB, "first pivot stackB");
	}

}

void	second_pivot(t_node **stackA, t_node **stackB)
{
	t_node	*pivot;
	t_node	*current;
	t_node	*next;

	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	while (*stackB != NULL)
	{
		pivot = *stackB;
		rotate_b(stackB);
		current = *stackB;
		while (current != pivot)
		{
			next = current->next;
			if (current->data > pivot->data)
				ft_push_b(stackB, stackA);
			else
				rotate_b(stackB);
			current = next;
		}
		ft_push_b(stackB, stackA);
	}
	print_stack(*stackA, "second pivot stackA");
    print_stack(*stackB, "second pivot stackB");
}

void	quicksort(t_node **stackA, t_node **stackB)
{
	first_pivot(stackA, stackB);
}
