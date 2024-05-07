/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:31:13 by msinke            #+#    #+#             */
/*   Updated: 2024/05/07 12:55:15 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stackA = NULL;
	t_node	*stackB = NULL;
	// t_node	*tryout = NULL;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		new_node(&stackA, ft_atoi(argv[i]));
		i--;
	}

	printf("Before sorting\n");
    printListAndPrevious(stackA);
	
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
