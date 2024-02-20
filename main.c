#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = load_stack(argc, argv, stack);

	// ft_display_stack(stack);
	// ft_printf("\n");
	// ft_pop_tail(stack);
	// ft_display_stack(stack);
	
	stack = sort_stack(stack);
	ft_free_stack(stack);
}
