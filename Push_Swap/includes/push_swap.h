/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:29 by msinke            #+#    #+#             */
/*   Updated: 2024/05/02 17:16:17 by milousinke       ###   ########.fr       */
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
void 	printList(t_node *node);
void	ft_pb(t_node **stackA, t_node **stackB);
void	ft_pa(t_node **stackA, t_node **stackB);
void	ft_swap(t_node **stackA);
void	ft_r(t_node **stackA);
void	ft_rr(t_node **stackA);
t_node	*first_pass(t_node *stackA);


#endif