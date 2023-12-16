NAME = push_swap
NAME_B = checker
SRC = main.c push_swap.c actions.c actions_utils1.c actions_utils2.c algos.c algos_utils1.c algos_utils2.c ft_atol.c manage_stack.c manage_stack_utils.c parse.c
SRC_B = checker.c checker_utilis.c manage_stack.c manage_stack_utils.c actions.c ft_atol.c
FLAGS = -Wall -Werror -Wextra
libft = ./libft/libft.a

all:$(NAME)

$(libft):
	@echo "[+] libft ..."
	@make -C ./libft -s

$(NAME): $(libft) $(SRC)
	@echo "[+] push swap ..."
	@gcc $(SRC) $(FLAGS) -o $(NAME) $(libft)
	@echo "[+] (push swap) DONE"

bonus:$(NAME_B)

$(NAME_B): $(libft)
	@echo "[+] checker ..."
	@gcc $(SRC_B) $(FLAGS) -o $(NAME_B) $(libft)

clean:
	@echo "[-] cleaning ..."
	@make clean -C ./libft -s
fclean:clean
	@echo "[-] clean all ..."
	@make fclean -C ./libft -s
	@rm -f $(NAME) $(NAME_B)
re:fclean all
