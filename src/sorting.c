/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:41:41 by lebartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:20:20 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_stack *stack_1, t_stack *stack_2);
void	swap(t_stack *a);
void	rotation(t_stack *a);
void	reverse_rotation(t_stack *a);
void	switch_top(t_stack *main, t_stack *temp);

void	sort(t_stack *a, t_stack *b)
{
	int		move;
	t_stack	*cost_a;
	t_stack	*cost_b;

	while (b->length > 0)
	{
		ft_get_sorting_costs(a, b, cost_a, cost_b);
		ft_execute_best_move(cost_a, cost_b);
	}
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (a->length <= 3)
		sort_3(a);
	else if (a->length == 5)
		sort_5(a, b);
	else
	{
		while (a->length > 3)
			push_to(a, b);
		sort_3(a);
		sort(a, b);
	}

	// t_stack	*temp_stack;
	// int		temp_value;

	// temp_stack = ft_initialize_stack(temp_stack);
	// push_to(stack, temp_stack);
	// while (stack->length > 0)
	// {
	// 	temp_value = ft_pop(stack);
	// 	while (temp_stack->head != NULL)
	// 	{
	// 		if (temp_value < temp_stack->head->value)
	// 			push_to(temp_stack, stack);
	// 		else
	// 			break ;
	// 	}
	// 	ft_push(temp_stack, temp_value);
	// 	ft_printf("pb\n");
	// }
	// while (temp_stack->length > 0)
	// 	push_to(temp_stack, stack);
	// ft_free_stack(temp_stack);
	// return (stack);
}

//str => if stack_1 == a => pb else pa
void	push_to(t_stack *stack_1, t_stack *stack_2)
{
	if (ft_is_stack_empty(stack_1))
		return ;
	stack_1 = ft_push(stack_2, ft_pop(stack_1));
}

void	swap(t_stack *a)
{
	int	temp;

	if (ft_is_stack_empty(a) || a->length < 2)
		return ;
	temp = a->head->value;
	a->head->value = a->head->next->value;
	a->head->next->value = temp;
}

void	reverse_rotation(t_stack *a)
{
	if (ft_is_stack_empty(a) || a->length < 2)
		return ;
	a = ft_push_tail(a, ft_pop(a));
}

void	rotation(t_stack *a)
{
	if (ft_is_stack_empty(a) || a->length < 2)
		return ;
	a = ft_push(a, ft_pop_tail(a));
}
