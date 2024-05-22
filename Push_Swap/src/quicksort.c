/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:24:00 by msinke            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:22 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	printf("while loop:\n");
	while (*stackA != NULL)
	{
		pivot = try_pivot(stackA, stackB, true);
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
	printf("while loop:\n");
	while (*stackB != NULL)
	{
		pivot = try_pivot(stackA, stackB, false);
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
		print_stack(*stackA, "second pivot stackA");
    	print_stack(*stackB, "second pivot stackB");
	}
	
}

t_node	*try_pivot(t_node **stackA, t_node **stackB, bool first_second)
{
	t_node	*pivot;

	//stackA calling
	if (first_second == true)
	{
		pivot = *stackA;
		while (pivot->pivot == true)
		{
			pivot = pivot->next;
			ft_push_b(stackA, stackB);
			
		}
		if (pivot->pivot == false)
		{
			pivot->pivot = true;
			return (pivot);
		}
	}
	if (first_second == false)
	{
		pivot = *stackB;
		while (pivot->pivot == true)
		{
			pivot = pivot->next;
			ft_push_a(stackB, stackA);
		}
		if (pivot->pivot == false)
		{
			pivot->pivot = true;
			return (pivot);
		}
	}
	return (pivot);
}

void	separate_a_b(t_node **stackA, t_node **stackB)
{
	t_node	*pivot;
	t_node	*current;
	t_node	*next;
	
	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
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

// void	second_stack_a(t_node **stackA, t_node **stackB)
// {
// 	t_node	*pivot;
// 	t_node	*current;
// 	t_node	*next;

// 	if (*stackA == NULL || (*stackA)->next == NULL)
// 		return ;
// 	pivot = *stackA;
	
// }

// t_node	*pivot(t_node **stackA, t_node **stackB)
// {
// 	t_node *firstpivot;
	
// }



void	quicksort(t_node **stackA, t_node **stackB)
{
	//make pivot search function
	
	// first pivot, does everything from stackA to stackB
	
	// second pivot, does opposite and goes from stackB to stackA
	// second_pivot(stackA, stackB);

	first_pivot(stackA, stackB);
	second_pivot(stackA, stackB);
	// while ((!ascending_check(stackA)) || (!(descending_check(stackB))) )
	// {
	// 	if (*stackA != NULL && (*stackA)->next != NULL)
	// 		first_pivot(stackA, stackB);
		
	// 	if (*stackB != NULL && (*stackB)->next != NULL)
	// 		second_pivot(stackA, stackB);
	// }
}
