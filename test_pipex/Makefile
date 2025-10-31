NAME = pipex
SRC = ../circle2/pipex/pipex.c ../circle2/pipex/commands.c ../circle2/pipex/executor.c ../circle2/pipex/here_doc.c ../circle2/pipex/ft_split_new.c ../circle2/pipex/ft_split_utils.c ../circle2/pipex/error.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = ../circle2/pipex/pipex_bonus.c ../circle2/pipex/commands.c ../circle2/pipex/executor.c ../circle2/pipex/here_doc.c ../circle2/pipex/ft_split_new.c ../circle2/pipex/ft_split_utils.c ../circle2/pipex/error.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror -O0 -g3
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
	@./pipex infile "cat" "wc" outfile; < infile cat | wc > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "invalidcmd123" "wc" outfile; < infile invalidcmd123 | wc > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
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

test_bonus:
	@rm -f errors.txt
	@./pipex here_doc EOF "cat" "wc -l" here_doc
	@ echo "here doc for bash:"
	@ cat << EOF | wc -l >> here_doc.txt
	@ diff here_doc.txt here_doc >> errors.txt 2>&1 || echo "Test failed" >> here_doc.txt
	@echo "=====================================" >> errors.txt
	@./pipex infile "cat" "grep a" "wc -w" outfile; < infile cat | grep a | wc -w > outfile.txt; diff outfile.txt outfile >> errors.txt 2>&1 || echo "Test failed" >> errors.txt
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
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose ./pipex ./file1.txt /bin/cat /bin/cat ./file2.txt


test_leaks_bonus:
	@echo "Running pipex (here_doc) with Valgrind to check for memory leaks..." 
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=definite --track-origins=yes \
		--gen-suppressions=all --log-file=valgrind_pipex_bonus.log \
		./$(NAME) here_doc EOF /bin/cat /bin/cat ./file2.txt
	@echo "Valgrind log saved to valgrind_pipex_bonus.log"

test_comprehensive_chatgpt:
	@echo "========================================="
	@echo "COMPREHENSIVE PIPEX TESTS"
	@echo "========================================="
	@rm -f test_results.txt
	
	# Test 1: Basic pipe
	@echo "\n[Test 1] Basic pipe: cat | wc -l" | tee -a test_results.txt
	@echo "hello\nworld\ntest" > test_input.txt
	@./pipex test_input.txt "cat" "wc -l" test_output.txt 2>test_err.txt
	@echo "Expected: 3" | tee -a test_results.txt
	@echo -n "Got: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< test_input.txt cat | wc -l > test_expected.txt
	@diff test_expected.txt test_output.txt && echo "✅ PASS" || echo "❌ FAIL"
	
	# Test 2: Command with arguments
	@echo "\n[Test 2] Command with args: grep hello | wc -l" | tee -a test_results.txt
	@echo "hello world\ntest\nhello again" > test_input.txt
	@./pipex test_input.txt "grep hello" "wc -l" test_output.txt 2>test_err.txt
	@echo -n "Got: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< test_input.txt grep hello | wc -l > test_expected.txt
	@diff test_expected.txt test_output.txt && echo "✅ PASS" || echo "❌ FAIL"
	
	# Test 3: Invalid first command
	@echo "\n[Test 3] Invalid first command: invalidcmd | wc" | tee -a test_results.txt
	@./pipex test_input.txt "invalidcmd123" "wc" test_output.txt 2>test_err.txt
	@echo -n "Your stderr: " | tee -a test_results.txt
	@cat test_err.txt | tee -a test_results.txt
	@echo -n "Your stdout: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< test_input.txt invalidcmd123 2>/dev/null | wc > test_expected.txt
	@diff test_expected.txt test_output.txt && echo "✅ PASS (output matches)" || echo "❌ FAIL (output differs)"
	
	# Test 4: Invalid second command
	@echo "\n[Test 4] Invalid second command: cat | invalidcmd" | tee -a test_results.txt
	@./pipex test_input.txt "cat" "invalidcmd123" test_output.txt 2>test_err.txt; echo "Exit code: $$?"
	@echo -n "Your stderr: " | tee -a test_results.txt
	@cat test_err.txt | tee -a test_results.txt
	@echo "Expected exit code: 127"
	
	# Test 5: Missing input file
	@echo "\n[Test 5] Missing input file" | tee -a test_results.txt
	@rm -f nonexistent_file.txt
	@./pipex nonexistent_file.txt "cat" "wc -l" test_output.txt 2>test_err.txt
	@echo -n "Your stderr: " | tee -a test_results.txt
	@cat test_err.txt | tee -a test_results.txt
	@echo -n "Your stdout: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< nonexistent_file.txt cat 2>/dev/null | wc -l > test_expected.txt 2>/dev/null || true
	@diff test_expected.txt test_output.txt && echo "✅ PASS" || echo "⚠️  Check manually"
	
	# Test 6: Empty command
	@echo "\n[Test 6] Empty command" | tee -a test_results.txt
	@./pipex test_input.txt "" "wc" test_output.txt 2>test_err.txt; echo "Exit code: $$?"
	@echo -n "Your stderr: " | tee -a test_results.txt
	@cat test_err.txt | tee -a test_results.txt
	@echo "Expected: Error message and exit code 127"
	
	# Test 7: Quoted arguments with spaces
	@echo "\n[Test 7] Quoted args: grep 'hello' | wc -l" | tee -a test_results.txt
	@./pipex test_input.txt "grep 'hello'" "wc -l" test_output.txt 2>test_err.txt
	@echo -n "Got: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< test_input.txt grep 'hello' | wc -l > test_expected.txt
	@diff test_expected.txt test_output.txt && echo "✅ PASS" || echo "❌ FAIL"
	
	# Test 8: Absolute path command
	@echo "\n[Test 8] Absolute path: /bin/cat | /usr/bin/wc" | tee -a test_results.txt
	@./pipex test_input.txt "/bin/cat" "/usr/bin/wc -l" test_output.txt 2>test_err.txt
	@echo -n "Got: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< test_input.txt /bin/cat | /usr/bin/wc -l > test_expected.txt
	@diff test_expected.txt test_output.txt && echo "✅ PASS" || echo "❌ FAIL"
	
	# Test 9: No PATH environment
	@echo "\n[Test 9] No PATH environment" | tee -a test_results.txt
	@env -i ./pipex test_input.txt "grep hello" "wc -l" test_output.txt 2>test_err.txt
	@echo -n "Your stderr: " | tee -a test_results.txt
	@cat test_err.txt | tee -a test_results.txt
	@echo -n "Your stdout: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@echo "Should find commands in /bin or /usr/bin"
	
	# Test 10: Complex awk command
	@echo "\n[Test 10] Complex awk with escaped quotes" | tee -a test_results.txt
	@echo "line1\nline2\nline3" > test_input.txt
	@./pipex test_input.txt "cat" 'awk "{count++} END {print count}"' test_output.txt 2>test_err.txt
	@echo -n "Got: " | tee -a test_results.txt
	@cat test_output.txt | tee -a test_results.txt
	@< test_input.txt cat | awk '{count++} END {print count}' > test_expected.txt
	@diff test_expected.txt test_output.txt && echo "✅ PASS" || echo "❌ FAIL"
	
	# Cleanup
	@echo "\n========================================="
	@echo "Test complete! Check test_results.txt for details"
	@echo "========================================="
	@rm -f test_input.txt test_output.txt test_expected.txt test_err.txt

test_memory_chatgpt:
	@echo "========================================="
	@echo "MEMORY LEAK TESTS"
	@echo "========================================="
	@echo "hello\nworld\ntest" > test_input.txt
	
	@echo "\n[Memory Test 1] Basic command"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
		--error-exitcode=42 --errors-for-leak-kinds=all \
		./pipex test_input.txt "cat" "wc -l" test_output.txt 2>&1 | grep -E "(LEAK SUMMARY|ERROR SUMMARY|Open file descriptor)"
	
	@echo "\n[Memory Test 2] Invalid command"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
		--error-exitcode=42 --errors-for-leak-kinds=all \
		./pipex test_input.txt "invalidcmd" "wc" test_output.txt 2>&1 | grep -E "(LEAK SUMMARY|ERROR SUMMARY|Open file descriptor)"
	
	@rm -f test_input.txt test_output.txt

test_exit_codes_chatgpt:
	@echo "========================================="
	@echo "EXIT CODE TESTS"
	@echo "========================================="
	@echo "hello\nworld" > test_input.txt
	
	@echo "\n[Exit Test 1] Success"
	@./pipex test_input.txt "cat" "wc -l" test_output.txt; echo "Exit code: $$?"
	@echo "Expected: 0"
	
	@echo "\n[Exit Test 2] First command fails"
	@./pipex test_input.txt "invalidcmd" "wc" test_output.txt 2>/dev/null; echo "Exit code: $$?"
	@echo "Expected: 0 (second command succeeds)"
	
	@echo "\n[Exit Test 3] Second command fails"
	@./pipex test_input.txt "cat" "invalidcmd" test_output.txt 2>/dev/null; echo "Exit code: $$?"
	@echo "Expected: 127 (command not found)"
	
	@echo "\n[Exit Test 4] Input file missing"
	@./pipex nonexistent.txt "cat" "wc" test_output.txt 2>/dev/null; echo "Exit code: $$?"
	@echo "Expected: 0 (second command still runs)"
	
	@rm -f test_input.txt test_output.txt

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
