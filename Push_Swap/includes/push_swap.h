/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milousinke <milousinke@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:29 by msinke            #+#    #+#             */
/*   Updated: 2024/05/23 19:23:12 by milousinke       ###   ########.fr       */
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
	bool			pivot;
	struct s_Node	*next;
	struct s_Node	*previous;
}	t_node;

t_node	*new_node(t_node **head, int data);
void	printList(t_node *node);
void	printListAndPrevious(t_node *head);
// operations
void	sa(t_node **stackA);
void	sb(t_node **stackB);
void	pa(t_node **source, t_node **dest);
void	pb(t_node **source, t_node **dest);
void	ra(t_node **stackA);
void	rb(t_node **stackA);
void	rra(t_node **stackA);
void	rrb(t_node	**stackB);
t_node	*first_pass(t_node *stackA);
void	sort_a_b(t_node **stackA, t_node **stackB);
void	sort_b_a(t_node **stackA, t_node **stackB);
int		ascending_check(t_node **stackA);
int		descending_check(t_node **stackB);
void	sort(t_node **stackA, t_node **stackB);
void	quicksort(t_node **stackA, t_node **stackB);
void	first_pivot(t_node **stackA, t_node **stackB);
void	second_pivot(t_node **stackA, t_node **stackB);
void	print_stack(t_node *stack, const char *name);
void	separate_a_b(t_node **stackA, t_node **stackB);
int     find_median(int x, int y, int z);
t_node  *ft_node_value(t_node *first, t_node *middle, t_node *last, int value);
t_node  *pivot_choice(t_node **stackA);
t_node	*try_pivot(t_node **stackA, t_node **stackB, bool first_second);

#endif