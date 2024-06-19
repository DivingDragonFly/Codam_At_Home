/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:31:13 by msinke            #+#    #+#             */
/*   Updated: 2024/06/19 17:39:20 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check arguments, whether they overflow, are actual numbers and dont have duplicates

#include "../includes/push_swap.h"

void	free_list(t_node **lst)
{
	t_node	*current;
	t_node	*temp;
	
	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = (current)->next;
		free(temp);
	}
    *lst = NULL;
}

void print_stack(t_node *stack, const char *name)
{
    printf("%s: ", name);
    while (stack != NULL)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int	main(int argc, char *argv[])
{
	t_node	*stackA = NULL;
	t_node	*stackB = NULL;
	int		i;
    int     *initial_sorting;

	i = argc - 1;
	// fix erorr cases (double int input, no number error)
	while (i > 0)
	{
		new_node(&stackA, ft_atoi(argv[i]));
		i--;
	}
	index(&stackA);
	// if (argc > 4)
    // {
    //     x = ft_atoi(argv[1]);
    //     y = ft_atoi(argv[((argc - 1) / 2)]);
    //     z = ft_atoi(argv[argc - 1]);
    //     c = pivot_choice(x, y, z);
    // }
	// if (argc < 4)
	// 	shortsort(stackA, stackB);
	printf("StackA:\n");
	printList(stackA);
	printf("StackB:\n");
	printList(stackB);
    // ascending_three_values(&stackA);
	printf("After:\nStackA:\n");
	printList(stackA);
	printf("StackB:\n");
	printList(stackB);
    // determining pivot

    //check for erros
    // are there any duplicates
    // is everything a number
	
	 // Free the allocated memory for both stack
    free_list(&stackA);
    free_list(&stackB);
	return (0);
}
