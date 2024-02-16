
#include "push_swap.h"

void	switch_top(t_stack *main, t_stack *temp);

t_stack	*sort_stack(t_stack *stack)
{
	t_stack	*temp_stack;
	int		temp_value;

	temp_stack = ft_initialize_stack(temp_stack);

	//FIRST CALL
	temp_value = stack->value;
	stack = ft_pop(stack);
	temp_stack = ft_push(temp_stack, temp_value);

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
	int	main_head_value;
	int	temp_head_value;

	if (ft_is_stack_empty(main))
	{
		temp_head_value = temp->value;
		temp = ft_pop(temp);
		main = ft_push(main, temp_head_value);
		return ;
	}
	if (ft_is_stack_empty(temp))
	{
		main_head_value = main->value;
		main = ft_pop(main);
		temp = ft_push(temp, main_head_value);
		return ;
	}


	main_head_value = main->value;
	temp_head_value = temp->value;

	temp = ft_pop(temp);
	main = ft_pop(main);
	main = ft_push(main, temp_head_value);
	temp = ft_push(temp, main_head_value);
}