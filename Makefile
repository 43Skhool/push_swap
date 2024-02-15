NAME		= push_swap

COREKIT_PATH = ./corekit

SRC = main.c \
	src/stack_loading.c

FLAGS		= -Wall -Werror -Wextra -g

OBJS		= $(SRC:%.c=%.o)

$(NAME): $(OBJS)
	@${MAKE} -s -C corekit
	@cc $(OBJS) -lm -L$(COREKIT_PATH) -lcorekit -Iincludes -o $(NAME) -s
	@echo "$(GREEN)[PUSH_SWAP]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

%.o: %.c
	@cc -c $< -o $@ -I$(COREKIT_PATH)/includes -Iincludes -s

clean:
	@rm -rf $(OBJS)
	@echo "$(RED)[PUSH_SWAP]:\t OBJECTS DELETED$(RESET)"
	@${MAKE} -C corekit clean -s

fclean: clean
	@rm -rf $(NAME)
	@${MAKE} -C corekit fclean -s
	@echo "$(RED)[PUSH_SWAP]:\t PUSH_SWAP FCLEAN$(RESET)"

re: fclean all

test: all
	 ./$(NAME) 4 3 -2147483648 23 4 5 6 2147483647

val: all
	 valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) "4 3 -2147483648 23 23 4 5 6 2147483648"

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m
