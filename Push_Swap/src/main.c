/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:31:13 by msinke            #+#    #+#             */
/*   Updated: 2024/05/22 17:49:34 by msinke           ###   ########.fr       */
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
	// t_node	*tryout = NULL;
	int		i;
	// int		p;

	i = argc - 1;
	// maybe determine pivot p = (argc - 1) / 2;
	// fix erorr cases (double int input, no number error)
	while (i > 0)
	{
		new_node(&stackA, ft_atoi(argv[i]));
		i--;
	}

	printf("Before quicksort\n");
    print_stack(stackA, "stackA");
    print_stack(stackB, "stackB");

    quicksort(&stackA, &stackB);

    printf("After quicksort\n");
    print_stack(stackA, "stackA");
    print_stack(stackB, "stackB");
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
