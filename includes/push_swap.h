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

t_stack	*sort_stack(t_stack *stack);

void	print_stacks(t_stack *main, t_stack *temp);

void	push_to_bottom(t_stack *main, int new_value);

#endif