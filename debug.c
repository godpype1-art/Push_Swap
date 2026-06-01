
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
	int		yy;
	int		where;

	stackA = init_stack(10);
	push(stackA, 8);
	push(stackA, 9);
	push(stackA, 2);
	push(stackA, 1);
	push(stackA, 3);
	push(stackA, 90);
	push(stackA, 24);
	push(stackA, 4);
	print_stack(stackA);

	yy = 1;
	while (yy < stackA->size)
	{
		where = yy;
		while (get(stackA, 0) > get(stackA, 1) && where > 0)
		{
			swap_first(stackA);
			//ft_putstr_fd("sa\n", 1);
			//print_stack(stackA);
			rotate(stackA);
			//ft_putstr_fd("ra\n", 1);
			//print_stack(stackA);
			where--;
		}
		while (where < yy)
		{
			reverse_rotate(stackA);
			//ft_putstr_fd("rra\n", 1);
			where++;
			//print_stack(stackA);
		}
		yy++;
		reverse_rotate(stackA);
		//ft_putstr_fd("rra\n", 1);
	}
	reverse_rotate(stackA);
	print_stack(stackA);
}