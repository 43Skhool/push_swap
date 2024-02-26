/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:00 by lebartol          #+#    #+#             */
/*   Updated: 2024/02/26 11:41:00 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = load_stack(argc, argv, stack);
	ft_display_stack(stack);
	ft_push(stack, 1);
	ft_push(stack, 2);
	ft_push(stack, 3);
	ft_printf("\n");
	push_to_bottom(stack, 5);
	//ft_pop_tail(stack);
	ft_display_stack(stack);
	// stack = sort_stack(stack);
	ft_free_stack(stack);
}
