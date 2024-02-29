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

void	display_stacks(t_stack *a, t_stack *b)
{
	ft_display_stack(a);
	ft_printf("^a\n");
	ft_display_stack(b);
	ft_printf("^b\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = load_stack(argc, argv, a);
	b = ft_initialize_stack(b);
	ft_push(b, 5);
	display_stacks(a, b);
	ft_printf("number of moves to insert %d:%d", 5, get_sorting_cost(b, b->head, a));
	ft_free_stack(a);
	ft_free_stack(b);
}
