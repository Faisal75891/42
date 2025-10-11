NAME = pipex.a
SRC = pipex.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ./ft_printf
PRINTF = ft_printf/libftprintf.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)  $(PRINTF)
	cp $(PRINTF) $(NAME)
	ar rcs $(NAME) $(SRC)

$(PRINTF):
	make -C $(PRINTF_DIR)

test: $(NAME)
	@cd test_pipex && ./a.out file1.txt /bin/cat /bin/ls file2.txt
	@echo "Test Completed. OUTPUT:"
	@cd test_pipex && cat file2.txt

test_bonus: $(NAME)
	@echo "Hello this is the test input WORD1.WORD2.WORD3.WORD4.WORD5.WORD6.WORD7.WORD8 the make file\nEOF\n" > test_pipex/input.txt
	@cd test_pipex && < input.txt ./a.out "here_doc" EOF /bin/cat /bin/cat file2.txt
	@echo "Test Completed. OUTPUT:"
	@cd test_pipex && cat file2.txt


clean:
	rm -f $(OBJ)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONEY: all clean fclean re
