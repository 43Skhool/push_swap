/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by lebartol          #+#    #+#             */
/*   Updated: 2024/03/18 16:53:33 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	if (is_stack_ordered(stack))
		return ;
	if (stack->head->value > stack->head->next->value)
		swap(stack);
	if (stack->head->value > stack->head->next->next->value)
		reverse_rotation(stack);
	if (stack->head->value > stack->head->next->value)
		swap(stack);
}

void	print_stacks(t_stack *main, t_stack *temp)
{
	ft_printf("\nMAIN STACK\n");
	ft_display_stack(main);
	ft_printf("\n\nTEMP STACK\n");
	ft_display_stack(temp);
	ft_printf("\n");
}

//Scorre tutto lo stack, se esiste qualocosa prima, se e minore e ordinato
t_bool	is_stack_ordered(t_stack *stack)
{
	t_stack_node	*temp_node;

	temp_node = stack->head;
	while (temp_node)
	{
		if (temp_node->prev)
		{
			if (temp_node->prev->value > temp_node->value)
				return (false);
		}
		temp_node = temp_node->next;
	}
	return (true);
}

int	get_position(t_stack *stack, t_stack_node *node)
{
	int				i;
	t_stack_node	*cursor;

	i = 0;
	cursor = stack->head;
	while (i < stack->length)
	{
		if (node == cursor)
			return (i);
		i++;
		cursor = cursor->next;
	}
	return (0);
}

int	get_selection_cost(t_stack *stack, t_stack_node *node)
{
	int	position;

	position = get_position(stack, node);
	if (position >= stack->length / 2)
		position = stack->length - position;
	return (position);
}

int	get_insertion_cost(t_stack *stack, int value)
{
	
}

t_stack	*get_sorting_costs(t_stack *a,t_stack *b)
{
	int			i;
	int			cost;
	t_stack		*temp;
	t_stack_node *node;

	i = 0;

	node = a->head;
	temp = ft_initialize_stack(temp);
	while (i < b->length)
	{
		cost = get_selection_cost(a, node) + abs(get_insertion_cost(b, node));
		ft_push_tail(temp, ft_create_node(cost));
		i++;
	}
}
