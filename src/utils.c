/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by lebartol          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:49 by lebartol         ###   ########.fr       */
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
int	get_selection_cost(t_stack *stack, t_stack_node *node)
{
	int	position;

	position = get_position(stack, node);
	if (position >= stack->length / 2)
		position = stack->length - position;
	return (position);
}

int	get_insertion_cost(void)
{

	return (0);
}

//down as mush as possible to make it less of a debugging pain
//it should account for it's position in the stack
// (the cost is basically how far it is from the middle)
//it should account for it's desired position in the other stack
//  the cost is again mostly
//  dependent on how far the desired position
//  (the two nodes that encapsulate it) is from the middle
// the logic is from the sorting algo
int	get_sorting_cost(t_stack *a, t_stack_node *node)
{
	return (get_insertion_cost() + get_selection_cost(a, node));
}
