#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "corekit.h"

t_stack	*load_stack(int argc, char **argv, t_stack *stack);

t_stack	*sort_stack(t_stack *stack);

void	print_stacks(t_stack *main, t_stack *temp);

#endif