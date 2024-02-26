/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by lebartol          #+#    #+#             */
/*   Updated: 2024/02/26 12:18:31 by lebartol         ###   ########.fr       */
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
