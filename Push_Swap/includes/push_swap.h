/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:29 by msinke            #+#    #+#             */
/*   Updated: 2024/04/26 16:30:02 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h>
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
}	t_node;

t_node	*new_node(t_node **head, int data);
void 	printList(t_node *node);
void	ft_pb(t_node **stackA, t_node **stackB);
void	ft_pa(t_node **stackA, t_node **stackB);
void	ft_sa(t_node **stackA);
void	ft_ra(t_node **stackA);
void	ft_rra(t_node **stackA);

#endif