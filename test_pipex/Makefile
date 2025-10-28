NAME = pipex
SRC = ../circle2/pipex/pipex.c ../circle2/pipex/commands.c ../circle2/pipex/executor.c ../circle2/pipex/here_doc.c ../circle2/pipex/ft_split_new.c ../circle2/pipex/ft_split_utils.c ../circle2/pipex/error.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = ../circle2/pipex/pipex_bonus.c ../circle2/pipex/commands.c ../circle2/pipex/executor.c ../circle2/pipex/here_doc.c ../circle2/pipex/ft_split_new.c ../circle2/pipex/ft_split_utils.c ../circle2/pipex/error.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
PRINTF_DIR = ../circle2/pipex/ft_printf
LIBFT_DIR = ../circle2/pipex/ft_printf/libft
PIPEX_DIR = ../circle2/pipex

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

bonus: $(OBJ_BONUS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

test:
	@echo "Running pipex tests..."
	@rm -f errors.txt
	@./pipex infile "cat" "wc -l" outfile; < infile cat | wc -l > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "cat" "grep a" "wc -w" outfile; < infile cat | grep a | wc -w > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "cat" "wc" outfile; < infile cat | wc > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "invalidcmd123" "wc" outfile; echo "Test: invalid command - your pipex output:"; cat outfile; echo "Shell would produce error for invalid command"
	@echo "=====================================" >> errors.txt
	@./pipex infile "" "wc" outfile; echo "Test: empty command - your pipex output:"; cat outfile; echo "Shell would produce error for empty command"
	@echo "=====================================" >> errors.txt
	@./pipex infile "grep 'hello'" "wc -l" outfile; < infile grep 'hello' | wc -l > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "ls" "grep pipex" outfile; < infile ls | grep pipex > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex nonexistent.txt "cat" "wc -l" outfile; < nonexistent.txt cat 2>/dev/null | wc -l > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "nonexistent_command" "wc" outfile; < infile nonexistent_command 2>/dev/null | wc > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "cat" "nonexistent_command" outfile; echo "Test: invalid second command - your pipex output:"; cat outfile; echo "Shell would produce error for invalid command"
	@echo "=====================================" >> errors.txt
	@./pipex infile "" "" outfile; echo "Test: both commands empty - your pipex output:"; cat outfile; echo "Shell would produce error for empty commands"
	@echo "=====================================" >> errors.txt
	@./pipex "" "cat" "wc" outfile; echo "Test: empty input file - your pipex output:"; cat outfile; echo "Shell would produce error for empty filename"
	@echo "=====================================" >> errors.txt
	@echo "Tests completed. Check errors.txt for results."

test_full_path:
	@rm -f errors.txt
	@ ./$(NAME) ./file1.txt /bin/cat /bin/cat ./file2.txt; < ./file1.txt cat | cat > outfile.txt; diff outfile.txt ./file2.txt >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@ ./$(NAME) ./file1.txt /bin/cat /bin/ls ./file2.txt; < ./file1.txt cat | ls > outfile.txt; diff outfile.txt ./file2.txt >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt

test_here_doc:
	@rm -f errors.txt
	@./pipex here_doc EOF "cat" "wc -l" here_doc
	@ echo "here doc for bash:"
	@ cat << EOF | wc -l >> here_doc.txt
	@ diff here_doc.txt here_doc >> errors.txt 2>&1 || echo "Test failed" >> here_doc.txt
	@echo "=====================================" >> errors.txt

test_simple:
	@echo "Running simple pipex test..."
	@./pipex infile "cat" "wc -l" outfile
	@echo "Expected output:"
	@< infile cat | wc -l
	@echo "Your output:"
	@cat outfile

test_leaks:
	@echo "Running pipex with Valgrind to check for memory leaks..."
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--verbose --log-file=valgrind_pipex.log \
		./$(NAME) ./file1.txt /bin/cat /bin/cat ./file2.txt
	@echo "Valgrind log saved to valgrind_pipex.log"

test_leaks_bonus:
	@echo "Running pipex (here_doc) with Valgrind to check for memory leaks..." 
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=definite --track-origins=yes \
		--gen-suppressions=all --log-file=valgrind_pipex_bonus.log \
		./$(NAME) here_doc EOF /bin/cat /bin/cat ./file2.txt
	@echo "Valgrind log saved to valgrind_pipex_bonus.log"

clean:
	rm -f pipex.o commands.o executor.o here_doc.o
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
