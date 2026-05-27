
#include <stdio.h>
#include "stack.h"

void print_stack(t_stack tsak)
{
	t_node *iterater = *(tsak.last);

	printf("size:%d\n", *(tsak.size));
	if (*(tsak.last) != NULL && *(tsak.first) != NULL)
	{
		printf("last:%d\n", (*(tsak.last))->value);
		printf("first:%d\n", (*(tsak.first))->value);
	}
	printf("%s", "stack final\n");
	while (iterater != NULL)
	{
		printf("%d\n", iterater->value);
		iterater = iterater->before;
	}
	printf("%s", "stack start\n");
}

int main()
{
	t_stack	stack;

	stack = init_stack();
	print_stack(stack);
	push(stack, 2);
	push(stack, 1);
	push(stack, 20);
	print_stack(stack);
	int value = pop(stack);
	printf("value:%d\n", value);
	print_stack(stack);
	value = pop(stack);
	printf("value:%d\n", value);
	print_stack(stack);

	push(stack, 32);
	push(stack, 31);
	print_stack(stack);
	value = popfirst(stack);
	printf("value:%d\n", value);
	print_stack(stack);
	pushfirst(stack, 40);
	print_stack(stack);
}