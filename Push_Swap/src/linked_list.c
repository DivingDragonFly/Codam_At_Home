/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:09 by msinke            #+#    #+#             */
/*   Updated: 2024/04/26 14:28:53 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(t_node **head, int data)
{
	t_node	*tmp;

	tmp = (t_node*)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = *head; // the pointer of the new node is set to point to the current head of the list
	// this inesrts the new node at the beginning of the list
	*head = tmp;
	// the head of the list is updated to point to the new node, mkaing it the new first node of the list
	return (tmp);
}

//funtion to test if it creates list properly
void printList(t_node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

