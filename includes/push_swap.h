/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:19:56 by lebartol          #+#    #+#             */
/*   Updated: 2024/02/26 11:19:56 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "corekit.h"

t_stack	*load_stack(int argc, char **argv, t_stack *stack);

void	ft_sort_stack(t_stack *a, t_stack *b);

void	ft_sort_three(t_stack *stack);

void	print_stacks(t_stack *main, t_stack *temp);

void	push_to(t_stack *stack_1, t_stack *stack_2);

void	swap(t_stack *a);

void	reverse_rotation(t_stack *a);

void	rotation(t_stack *a);

t_bool	is_stack_ordered(t_stack *stack);

void	get_sorting_costs(t_stack *a, t_stack *b, t_stack *cost_a, t_stack *cost_b);

int	get_selection_cost(t_stack *a, t_stack_node *node);

void	display_stacks(t_stack *a, t_stack *b);

#endif