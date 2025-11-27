/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:18:39 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 22:18:39 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

/*
int	parse_arguments(int argc, char **argv, int *int_array)
{
	char	**args;
	int		i;
	int		last;

	if (!argv)
		return (0);
	i = 0;
	last = argc;
	if (argc == 2)
	{
		last = 0;
		if (!argv[1])
			return (0);
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
		while (args[last])
			last++;
		last--;
		while(args[i])
		{
			if  (!is_valid_number(args[last]))
				return (0);
			int_array[i] = ft_atoi(args[last]);
			i++;
			last--;
		}
		return (i);
	}
	else
	{
		while (i < argc - 1)
		{
			if (!is_valid_number(argv[last - 1]));
				return (0);
			int_array[i] = ft_atoi(argv[last - 1]);
			i++;
			last--;
		}
	}
	return(i);
}
*/

void	setUp(void) {}
void	tearDown(void) {}

void	test_single_string(void)
{
	char	*argv[] = {"./push_swap", "1 2 3 4"};
	int		argc = 2;
	int		*int_array = malloc(4 * sizeof(int));
	int		expected[] = {4, 3, 2, 1};

	int		result = parse_arguments(argc, argv, int_array);

	TEST_ASSERT_EQUAL_INT (4, result);
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, int_array, 4);
	free(int_array);
}

void	test_multiple_strings(void)
{
	char	*argv[] = {"./push_swap", "1", "2", "3", "4"};
	int		argc = 5;
	int		*int_array = malloc(4 * sizeof(int));
	int		expected[] = {4, 3, 2, 1};

	int		result = parse_arguments(argc, argv, int_array);

	TEST_ASSERT_EQUAL_INT (4, result);
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, int_array, 4);
	free(int_array);
}

void	test_invalid(void)
{
	char	*argv[] = {"./push_swap", "abc", "ab2", "123"};
	int		argc = 4;
	int		*int_array = malloc(3 * sizeof(int));

	int	result = parse_arguments(argc, argv, int_array);
	TEST_ASSERT_EQUAL_INT(0, result);
	free(int_array);
}

void	test_null(void)
{
	char	*argv[] = {"./push_swap", ""};
	int		argc = 2;
	int		*int_array = malloc(1 * sizeof(int));

	int	result = parse_arguments(argc, argv, int_array);
	TEST_ASSERT_EQUAL_INT(0, result);
	free(int_array);
}

void	test_two_numbers(void)
{
	char	*argv[] = {"./push_swap", "1", "2"};
	int		argc = 3;
	int		*int_array = malloc(2 * sizeof(int));
	int		expected[] = {2, 1};

	int		result = parse_arguments(argc, argv, int_array);

	TEST_ASSERT_EQUAL_INT (2, result);
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, int_array, 2);
	free(int_array);
}

void	test_one_number(void)
{
	char	*argv[] = {"./push_swap", "1"};
	int		argc = 2;
	int		*int_array = malloc(1 * sizeof(int));
	int		expected[] = {1};

	int		result = parse_arguments(argc, argv, int_array);

	TEST_ASSERT_EQUAL_INT (1, result);
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, int_array, 1);
	free(int_array);
}

// FYI: argc will never be less than 2 in the main function.
int	main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_null);
	RUN_TEST(test_multiple_strings);
	RUN_TEST(test_single_string);
	RUN_TEST(test_invalid);
	RUN_TEST(test_two_numbers);
	RUN_TEST(test_one_number);
	return UNITY_END();
}
