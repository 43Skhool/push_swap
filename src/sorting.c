
#include "push_swap.h"

void	switch_top(t_stack *main, t_stack *temp);

t_stack	*sort_stack(t_stack *stack)
{
	t_stack	*temp_stack;
	int		temp_value;

	temp_stack = ft_initialize_stack(temp_stack);

	//FIRST CALL
	temp_value = ft_pop(stack);
	ft_push(temp_stack, temp_value);

	print_stacks(stack, temp_stack);

	// //switch_top(stack, temp_stack);
	// print_stacks(stack, temp_stack);

	// while (!stack)
	// {
	// 	if (stack->value < temp_stack->value)
	// 	{
	// 		switch_top(stack, temp_stack);
	// 	}
	// }
	//ft_display_stack(stack);

	ft_free_stack(temp_stack);

	return (stack);
}

void	switch_top(t_stack *main, t_stack *temp)
{
	ft_push(temp, ft_pop(main));
}