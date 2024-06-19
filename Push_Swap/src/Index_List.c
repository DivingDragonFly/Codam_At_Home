/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Index_List.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:34:25 by msinke            #+#    #+#             */
/*   Updated: 2024/06/04 16:09:45 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node_sorted_list(int data)
{
	t_node	*tmp;

	tmp = (t_node*)malloc (sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

void	sort_insertion(t_node **head, t_node *new_node)
{
	t_node	*lst;
	
	if (new_node->data < (*head)->data)
	{
		new_node->next = *head;
		*head = new_node;
		return ;
	}
	lst = *head;
	while (lst->next != NULL && lst->next->data < new_node->data)
		lst = lst->next;
	new_node->next = lst->next;
	lst->next = new_node;
}
	
t_node	*sort_list(t_node *unsorted_lst)
{
	t_node	*sorted_stack = NULL;
	t_node			*new_node;

	while (unsorted_lst != NULL)
	{
		new_node = new_node_sorted_list(unsorted_lst->data);
		if (!new_node)
		{
			free_list(&unsorted_lst);
			return (NULL);
		}
		if (sorted_stack == NULL)
			sorted_stack = new_node;
		else
			sort_insertion(&sorted_stack, new_node);
		unsorted_lst = unsorted_lst->next;
	}
	return (sorted_stack);
}

int	find_index(t_node *sorted_list, int value)
{
	t_node	*current;
	int		count;
	
	count = 0;
	current = sorted_list;
	while (current->data != value)
	{
		current = current->next;
		count++;		
	}
	count++;
	return (count);
}

void	index_list(t_node **stackA)
{
	t_node	*sorted_list;
	t_node	*temp;
	int		index;
	//create sorted list
	index = 0;
	sorted_list = NULL;
	sorted_list = sort_list(*stackA);
	if (!sorted_list)
		free_list(stackA);
	temp = *stackA;
	while (temp != NULL)
	{
		index = find_index(sorted_list, temp->data);
		temp->data = index;
		temp = temp->next;
	}
	free_list(&sorted_list);
}
