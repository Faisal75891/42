NAME = pipex
SRC = pipex.c commands.c executor.c here_doc.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./ft_printf/libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o ./test_pipex/$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

test:
	@echo "Creating test input file"
	@echo "Hello World from pipex!" > test_pipex/file1.txt
	@echo "Running pipex test..."
	@cd test_pipex && ./$(NAME) file1.txt /bin/cat /bin/cat file2.txt
	@echo "Test Completed. OUTPUT:"
	@cd test_pipex && cat file2.txt

test_bonus:
	@./test_pipex/$(NAME) here_doc EOF /bin/cat /bin/cat ./test_pipex/file2.txt
	@echo "Test Completed. OUTPUT:"
	@cd test_pipex && cat file2.txt

test_leaks:
	@echo "Running pipex with Valgrind to check for memory leaks..."
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--verbose --log-file=valgrind_pipex.log \
		./test_pipex/$(NAME) ./test_pipex/file1.txt /bin/cat /bin/cat ./test_pipex/file2.txt
	@echo "Valgrind log saved to valgrind_pipex.log"

test_leaks_bonus:
	@echo "Running pipex (here_doc) with Valgrind to check for memory leaks..." 
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=definite --track-origins=yes \
		--gen-suppressions=all --log-file=valgrind_pipex_bonus.log \
		./test_pipex/$(NAME) here_doc EOF /bin/cat /bin/cat ./test_pipex/file2.txt
	@echo "Valgrind log saved to valgrind_pipex_bonus.log"

clean:
	rm -f $(OBJ)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
