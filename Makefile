NAME		= push_swap

COREKIT_PATH = ./corekit

SRC = main.c \
	src/stack_loading.c \
	src/sorting.c \
	src/utils.c

FLAGS		= -Wall -Werror -Wextra -g

OBJS		= $(SRC:%.c=%.o)

$(NAME): $(OBJS)
	@${MAKE} -s -C corekit
	@cc $(OBJS) -lm -L$(COREKIT_PATH) -lcorekit -Iincludes -o $(NAME) -g
	@echo "$(GREEN)[PUSH_SWAP]:\t PROJECT COMPILED$(RESET)"

#TO DO mettere le flag

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
	 ./$(NAME) 4 

val: all
	 valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) 78 48 17 36 65 93 10 21 79 74 41 19 8 38 71 32 77 51 80 69 43 72 44 95 82 96 1 91 22 13 99 68 62 66 5 73 27 9 7 2 98 92 50 3 87 58 67 46 16 28 52 40 45 75 6 35 49 47 37 55 33 15 14 29 23 53 25 24 97 76 42 54 11 4 86 83 59 26 56 0 39 90 63 60 31 94 89 81 64 61 18 34 70 57 12 84 30 88 85 20

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m
