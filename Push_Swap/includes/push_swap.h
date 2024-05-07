/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:29 by msinke            #+#    #+#             */
/*   Updated: 2024/05/07 12:37:39 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_Node
{
	int				data;
	struct s_Node	*next;
	struct s_Node	*previous;
}	t_node;

t_node	*new_node(t_node **head, int data);
void	printList(t_node *node);
void	printListAndPrevious(t_node *head);
void	ft_pb(t_node **stackA, t_node **stackB);
void	ft_pa(t_node **stackA, t_node **stackB);
void	ft_swap(t_node **stackA);
void	ft_r(t_node **stackA);
void	ft_rr(t_node **stackA);
t_node	*first_pass(t_node *stackA);
void	sort_a_b(t_node **stackA, t_node **stackB);
void	sort_b_a(t_node **stackA, t_node **stackB);
int		ascending_check(t_node **stackA);
int		descending_check(t_node **stackB);
void	sort(t_node **stackA, t_node **stackB);

#endif