/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:47:47 by msinke            #+#    #+#             */
/*   Updated: 2024/05/03 17:48:17 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*first_pass(t_node *stackA)
{
	t_node	*current;
	t_node	*head;

	if (stackA == NULL)
		return (NULL);
	head = stackA;
	current = stackA->next;
	while (current != NULL)
	{
		if (current->data < head->data)
			head = current;
		current = current->next;
	}
	return (head);
}
