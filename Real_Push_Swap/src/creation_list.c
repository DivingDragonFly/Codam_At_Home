/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:02:15 by msinke            #+#    #+#             */
/*   Updated: 2024/06/13 16:48:29 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_node *stackA, t_node *stackB)
{
	...	
}

void	create_stack(t_node *stackA, t_node *stackB)
{
	...
}

void	new_node_stack(t_node **head, int data)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

void	print_list(t_node *node)
{
	while (node != NULL)
	{
		printf("%d", node->data);
		node = node->next;
	}
	printf("\n");
}
