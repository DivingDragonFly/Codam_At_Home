/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:31:13 by msinke            #+#    #+#             */
/*   Updated: 2024/05/02 19:57:26 by milousinke       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stackA = NULL;
	t_node	*stackB = NULL;
	t_node	*tryout = NULL;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		new_node(&stackA, ft_atoi(argv[i]));
		i--;
	}

	printList(stackA);
	tryout = first_pass(stackA);
	if (tryout != NULL)
		printf("The smallest value found: %d\n", tryout->data);
	else
		printf("The list is emtpy. \n");
	// printf("%d", tryout.data);

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


//first argument should be at the top of the stack