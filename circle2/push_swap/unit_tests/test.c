
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int *collection;
	int capacity;
	int size;
} t_stack;

t_stack	*create_stack(int capacity)
{
	t_stack *stack;

	if (capacity <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
 		return (NULL);
	stack->collection = malloc(sizeof(int) * capacity);
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

int	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

int	push(t_stack *stack, int *item)
{
	if (is_full(stack))
		return (1);
	stack->collection[stack->size] = *item;
	stack->size++;
	return (0);
}

int	cost_to_top(t_stack *stack, int position)
{
	int	rotate_cost;
	int	reverse_rotate_cost;

	//if (position < 0)
	//	position = find_position(stack, find_max(stack));
	rotate_cost = position;
	reverse_rotate_cost = stack->size - position;
	if (rotate_cost <= reverse_rotate_cost)
		return (rotate_cost);
	else
		return (-reverse_rotate_cost);
}

int main()
{
    t_stack *a = create_stack(11);
    int item = 3;
    push(a, &item); // 0
    push(a, &item); // 1
    push(a, &item); // 2
    push(a, &item); // 3
    push(a, &item); // 4
    push(a, &item); // 5
    push(a, &item); // 6
    push(a, &item); // 7
    push(a, &item); // 8
    push(a, &item); // 9
    push(a, &item); // 10

    printf("cost to top %d\n", cost_to_top(a, 0));
    printf("cost to top %d\n", cost_to_top(a, 1));
    printf("cost to top %d\n", cost_to_top(a, 2));
    printf("cost to top %d\n", cost_to_top(a, 3));
    printf("cost to top %d\n", cost_to_top(a, 4));
    printf("cost to top %d\n", cost_to_top(a, 5));
    printf("cost to top %d\n", cost_to_top(a, 6));
    printf("cost to top %d\n", cost_to_top(a, 7));
    printf("cost to top %d\n", cost_to_top(a, 8));
    printf("cost to top %d\n", cost_to_top(a, 9));
    printf("cost to top %d\n", cost_to_top(a, 10));
}