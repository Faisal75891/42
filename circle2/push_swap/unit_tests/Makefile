UNITY_DIR = unity
UNITY_SRC = $(UNITY_DIR)/unity.c

FLAGS = -I $(UNITY_DIR)

# Your source files
UTILS = utils/*.c
SORT_UTILS = sort_utils/*.c
UNIT_TESTS_DIR = unit_tests/

# Test targets
test_smallest_bigger: unit_tests/test_smallest_bigger.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_cost_to_top: unit_tests/test_cost_to_top.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_is_sorted: unit_tests/test_is_sorted.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_best_index_to_move: unit_tests/test_best_index_to_move.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(SORT_UTILS) $(UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@
	
test_parse_arguments: $(UNIT_TESTS_DIR)/test_parse_arguments.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_push_args: $(UNIT_TESTS_DIR)/test_push_args.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_push_into_stack: $(UNIT_TESTS_DIR)/test_push_into_stack.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@  && rm $@

test_rotate_to_top: $(UNIT_TESTS_DIR)/test_rotate_to_top.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_find_position: $(UNIT_TESTS_DIR)/test_find_position.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_find_max: $(UNIT_TESTS_DIR)/test_find_max.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test_put_max_top: $(UNIT_TESTS_DIR)/test_put_max_top.c $(PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) $< $(UNITY_SRC) $(UTILS) $(SORT_UTILS) $(PRINTF) $(LIBFT) -o $@ && ./$@

test: test_smallest_bigger test_cost_to_top test_is_sorted test_best_index_to_move test_parse_arguments test_push_args test_push_into_stack test_rotate_to_top test_find_position test_find_max test_put_max_top

clean_tests:
	rm -f test_*

	test_three:
	@echo "============================="
	@./push_swap 1 2 3
	@echo "============================="
	@./push_swap 1 3 2
	@echo "============================="
	@./push_swap 2 1 3
	@echo "============================="
	@./push_swap 2 3 1
	@echo "============================="
	@./push_swap 3 1 2
	@echo "============================="
	@./push_swap 3 2 1
	@echo "============================="
	@./push_swap 2 1
	@echo "============================="
	@./push_swap 1 2
	@echo "============================="

TESTS_OBJ = $(TESTS:.c=.o);

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
