/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:56:05 by msinke            #+#    #+#             */
/*   Updated: 2024/06/13 18:18:01 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
	//check if enough arguments
	// check whether arguments are all int
	// check whether their are no duplicates
	if (argc < 1)
		error_exit();
	if (argc == 2)
		parse_argv(argc, argv[2]);
	// init_stack(&a, &b);
	while (i > 0)
	{
		new_node_stack(&stack_a, ft_atoi(argv[i]));
		i--;
	}
}
