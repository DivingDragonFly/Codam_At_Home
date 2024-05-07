/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:09 by msinke            #+#    #+#             */
/*   Updated: 2024/05/07 12:57:47 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(t_node **head, int data)
{
	t_node	*tmp;

	tmp = (t_node*)malloc (sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = *head; // the pointer of the new node is set to point to the current head of the list
	// this inesrts the new node at the beginning of the list
	tmp->previous = NULL; //As this will be the new head, its previous should be NULL
	if (*head != NULL)
		(*head)->previous = tmp; // if the list was not empty, update the previous head
	*head = tmp;
	// the head of the list is updated to point to the new node, mkaing it the new first node of the list
	return (tmp);
}
// delete previous unnecessary
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

void printListAndPrevious(t_node *head)
{
    t_node *current = head;

    printf("Forward traversal:\n");
    while (current != NULL) {
        printf("Node %d, Next: ", current->data);
        if (current->next != NULL)
            printf("%d", current->next->data);
        else
            printf("(nil)");
        printf(", Previous: ");
        if (current->previous != NULL)
            printf("%d\n", current->previous->data);
        else
            printf("(nil)\n");
        current = current->next;
    }

    printf("Backward traversal:\n");
    current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("Node %d, Next: ", current->data);
        if (current->next != NULL)
            printf("%d", current->next->data);
        else
            printf("(nil)");
        printf(", Previous: ");
        if (current->previous != NULL)
            printf("%d\n", current->previous->data);
        else
            printf("(nil)\n");
        current = current->previous;
    }
}



