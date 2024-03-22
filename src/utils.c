/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by lebartol          #+#    #+#             */
/*   Updated: 2024/03/21 18:44:35 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	t_stack_node *n;

	if (is_stack_ordered(stack))
		return ;
	n = stack->head;
	if (n->value < n->next->value)
	{
		rotation(stack);
		if (is_stack_ordered(stack))
			return ;
	}
	if (n->value > n->next->value)
	{
		if (n->value > n->next->next->value)
			reverse_rotation(stack);
		if (is_stack_ordered(stack))
			return ;
	}
	swap(stack);
}
//this is bad. 
int	greatest_smaller_than(t_stack *stack, int value)
{
	t_stack_node	*cursor;
	int				target;

	target = value;
	cursor = stack->head;
	while (cursor->next != NULL)
	{
		if (cursor->value < value && (value == target || cursor->value > target))
			target = cursor->value;
		cursor = cursor->next;
	}
	return (target);
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

//gets the position, first value is 0
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

//visto che possiamo inserire soltanto il primo elemento
//nell'altro stack dobbiamo cercare il modo di portarcelo
//non metto il controllo che il nodo sia effettivamente nello stack
// se la dimensione e' <2
//potrebbe essere necessario cambiare il tipo di dato in futuro
// visto che le mosse potrebbero essere <MAX_INT
// questo metodo è un affronto a dio non dovrebbe esistere
int	get_insertion_cost(t_stack *b, int value)
{
	int	cost;
	int	position;

	position = get_position(b, ft_stack_contains(b, value));
	if (position > b->length / 2)
		cost = -(b->length - position);
	else
		cost = position;
	return (cost);
}

int	max_value(t_stack *stack)
{
	int max;
	t_stack_node *node;

	node = stack->head;
	max = stack->head->value;
	while (node->next != NULL)
	{
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}
//down as mush as possible to make it less of a debugging pain
//it should account for it's position in the stack
// (the cost is basically how far it is from the middle)
//it should account for it's desired position in the other stack
//  the cost is again mostly
//  dependent on how far the desired position
//  (the two nodes that encapsulate it) is from the middle
// the logic is from the sorting algo
// should add max and min in struct for easier handling
int	get_selection_cost(t_stack *a, t_stack_node *node)
{
	int				target;

	target = greatest_smaller_than(a, node->value);
	if (target == node->value)
		target = max_value(a);
	return (get_insertion_cost(a, target));
}



void	get_sorting_costs(t_stack *a, t_stack *b, t_stack *cost_a, t_stack *cost_b)
{
	int cost;
	t_stack_node *node;

	node = b->head;
	while (node->next != NULL)
	{
		ft_push_tail(cost_a, get_selection_cost(a, node->value));
		ft_push_tail(cost_b, get_insertion_cost(b, node->value));
		node = node->next;
	}
}
