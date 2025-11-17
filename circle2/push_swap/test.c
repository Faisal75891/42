
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main()
{
    t_stack *a = create_stack(11);
    int item = 3;
    push(a, &item); // 0
	item = 4;
    push(a, &item); // 1
	item = 5;
    push(a, &item); // 2
	item = 6;
    push(a, &item); // 3
	item = 7;
    push(a, &item); // 4
	item = 8;
    push(a, &item); // 5
	item = 9;
    push(a, &item); // 6
	item = 10;
    push(a, &item); // 7
	item = 11;
    push(a, &item); // 8
	item = 12;
    push(a, &item); // 9
	item = 13;
    push(a, &item); // 10

	rotate_to_top(a, 9, 1);
    printf("cost to top for index 0 %d\n", cost_to_top(a, 0));
    printf("cost to top for index 1 %d\n", cost_to_top(a, 1));
    printf("cost to top for index 2 %d\n", cost_to_top(a, 2));
    printf("cost to top for index 3 %d\n", cost_to_top(a, 3));
    printf("cost to top for index 4 %d\n", cost_to_top(a, 4));
    printf("cost to top for index 5 %d\n", cost_to_top(a, 5));
    printf("cost to top for index 6 %d\n", cost_to_top(a, 6));
    printf("cost to top for index 7 %d\n", cost_to_top(a, 7));
    printf("cost to top for index 8 %d\n", cost_to_top(a, 8));
    printf("cost to top for index 9 %d\n", cost_to_top(a, 9));
    printf("cost to top for index 10 %d\n", cost_to_top(a, 10));
}