
void print_stack(t_stack *tsak)
{
	int i = 0;
	printf("%s\n", "start");
	while (i < tsak->size)
		printf("%d\n", get(tsak, i++));
	printf("%s\n", "end");
}

int main()
{
	t_stack	*stack;

	stack = init_stack(8);
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
	push(stack, 23);
	push(stack, 31);
	print_stack(stack);

	rotate(stack);
	print_stack(stack);
	reverse_rotate(stack);
	print_stack(stack);
	swap_first(stack);
	print_stack(stack);
}