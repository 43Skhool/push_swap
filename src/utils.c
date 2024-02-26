/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by lebartol          #+#    #+#             */
/*   Updated: 2024/02/26 11:47:39 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *main, t_stack *temp)
{
	ft_printf("\nMAIN STACK\n");
	ft_display_stack(main);
	ft_printf("\n\nTEMP STACK\n");
	ft_display_stack(temp);
	ft_printf("\n");
}

void	push_to_bottom(t_stack *stack, int new_value)
{
	t_stack_node	*updated_tail;

	updated_tail = ft_create_node(new_value);
	if (ft_is_stack_empty(stack))
	{
		stack->head = updated_tail;
		stack->tail = stack->head;
	}
	else
	{
		updated_tail->prev = stack->tail;
		stack->tail->next = updated_tail;
		stack->tail = updated_tail;
	}
	stack->length++;
	return (stack);
}
