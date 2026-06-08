
#include "push_swap.h"

void print_stack(t_stack *tsak)
{
	int i = 0;
	printf("start:%d, end:%d\n", tsak->start, tsak->end);
	printf("size:%d, allocated_size:%d\n", tsak->size, tsak->allocated_size);
	while (i < tsak->allocated_size)
		printf("%d, ", tsak->array[i++]);
	printf("\n");
	i = 0;
	printf("%s\n", "start");
	while (i < tsak->size)
		printf("%d\n", get(tsak, i++));
	printf("%s\n", "end");
}

int main()
{
	t_stack	*stackA;
    t_stack	*stackB;
	int		yy;
	int		where;

	stackA = init_stack(10);
	stackB = init_stack(10);
	push(stackA, 11);
	push(stackA, 10);
	push(stackA, 3);
	push(stackA, 22);
	push(stackA, 31);
	push(stackA, 30);
	push(stackA, 4);
	push(stackA, 2);
	push(stackA, 1);
	print_stack(stackA);

	merge_sorting(stackA);
	//merge(stackA, stackB, 0, 3, 6);
	print_stack(stackA);
}
