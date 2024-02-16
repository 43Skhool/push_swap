#include "push_swap.h"

t_bool	double_check_number(int number, char *str_number);
void	error(int argc, char **argv, t_stack *stack);
char	**take_arguments(int argc, char **argv, int *i);

// tmp_number è long per eviatare soliti problemi con il minimo intero
// Se argc = 2
//	->il formato è "1 2 3 4 5"->va splittato e la i parte da 0
// Altrimenti
//	->il formato è 1 2 3 4 5->già splittato e la i parte 1
// CARICAMENTO
// Se la stringa non è un numero
//	->errore
// Prendi il numero (atoi)
// Fai la riprova (itoa)
//	->errore
t_stack	*load_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	char	**argv_splitted;
	long	tmp_number;

	stack = NULL;
	argv_splitted = take_arguments(argc, argv, &i);
	while (argv_splitted[i])
	{
		if (ft_is_string_numeric(argv_splitted[i]) == false)
			error(argc, argv_splitted, stack);
		tmp_number = ft_atoi(argv_splitted[i]);
		if (double_check_number(tmp_number, argv_splitted[i]) == false)
			error(argc, argv_splitted, stack);
		if (ft_stack_contains(stack, tmp_number) == true)
			error(argc, argv_splitted, stack);
		stack = ft_push(stack, tmp_number);
		i++;
	}
	if (argc == 2)
		ft_free_matrix((void **)argv_splitted);
	return (stack);
}

//i is just for norminette
char	**take_arguments(int argc, char **argv, int *i)
{
	char	**result;

	if (argc == 1)
		error(argc, argv, NULL);
	if (argc == 2)
	{
		*i = 0;
		result = ft_split(argv[1], ' ');
		if (ft_count_matrix_row((void **)result) == 0)
			error(argc, result, NULL);
	}
	else
	{
		*i = 1;
		result = argv;
	}
	return (result);
}

t_bool	double_check_number(int number, char *str_number)
{
	t_bool	result;
	char	*right_str_nmbr;

	right_str_nmbr = ft_itoa(number);
	if (ft_strncmp(str_number, right_str_nmbr, ft_strlen(str_number)) == 0)
		result = true;
	else
		result = false;
	free(right_str_nmbr);
	return (result);
}

//Argc perchè se facessi free indistintamente che sia splittato
//o il parametro originale, nel sel secondo caso darebbe
//invalid pointer
void	error(int argc, char **argv, t_stack *stack)
{
	if (argc == 2)
		ft_free_matrix((void **)argv);
	ft_free_stack(stack);
	ft_printf("Error in parameters\n");
	exit(0);
}
