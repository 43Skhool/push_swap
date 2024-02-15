#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = load_stack(argc, argv);
	ft_display_stack(stack);
	ft_free_stack(stack);
}
