#include "../include/push_swap.h"

void	sm(t_stack **a, t_stack **b, char c)
{
	if (c == 'a' || c == 's')
		swap(a);
	if (c == 'b' || c == 's')
		swap(b);
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rm(t_stack **a, t_stack **b, char c)
{
	if (c == 'a' || c == 'r')
		rotate(a);
	if (c == 'b' || c == 'r')
		rotate(b);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rrm(t_stack **a, t_stack **b, char c)
{
	if (c == 'a' || c == 'r')
		reverse_rotate(a);
	if (c == 'b' || c == 'r')
		reverse_rotate(b);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	pm(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		push(b, a);
	else
		push(a, b);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
