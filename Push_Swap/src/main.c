/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:31:13 by msinke            #+#    #+#             */
/*   Updated: 2024/05/29 11:29:37 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// make sure the error messages are on the standard error
// check arguments, whether they overflow, are actual numbers and dont have duplicates

#include "../includes/push_swap.h"

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
    // t_node  *pivot = NULL;
	int		i;
	// int     x;
    // int     y;
    // int     z;
    // int     c;

	i = argc - 1;
	// maybe determine pivot p = (argc - 1) / 2;
	// fix erorr cases (double int input, no number error)
	while (i > 0)
	{
		new_node(&stackA, ft_atoi(argv[i]));
		i--;
	}
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
    initial_partition(&stackA, &stackB);
    // ascending_three_values(&stackA);
	printf("After:\nStackA:\n");
	printList(stackA);
	printf("StackB:\n");
	printList(stackB);
    // determining pivot

	// printf("Before quicksort\n");
    // print_stack(stackA, "stackA");
    // print_stack(stackB, "stackB");

    // quicksort(&stackA, &stackB);

    // printf("After quicksort\n");
    // print_stack(stackA, "stackA");
    // print_stack(stackB, "stackB");
	 // Free the allocated memory for both stack
    while (stackA != NULL) {
        t_node *temp = stackA;
        stackA = stackA->next;
        free(temp);
    }
    while (stackB != NULL) {
        t_node *temp = stackB;
        stackB = stackB->next;
        free(temp);
    }
	return (0);
}
