
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

	stackA = init_stack(1);
	push(stackA, 4);
	push(stackA, 3);
	push(stackA, 2);
	push(stackA, 1);
	print_stack(stackA);

	//merge_sorting(stackA);
	//merge(stackA, stackB, 0, 3, 6);
	//print_stack(stackA);
}
