#include "../include/push_swap.h"

static void	push_to_a_rr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		rm(a, b, 'r');
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		rm(a, b, 'a');
		steps_a--;
	}
	while (steps_b)
	{
		rm(a, b, 'b');
		steps_b--;
	}
}

static void	push_to_a_rrr(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a && steps_b)
	{
		rrm(a, b, 'r');
		steps_a--;
		steps_b--;
	}
	while (steps_a)
	{
		rrm(a, b, 'a');
		steps_a--;
	}
	while (steps_b)
	{
		rrm(a, b, 'b');
		steps_b--;
	}
}

static void	push_to_a_rmrrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		rm(a, b, 'a');
		steps_a--;
	}
	while (steps_b)
	{
		rrm(a, b, 'b');
		steps_b--;
	}
}

static void	push_to_a_rrmrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
{
	while (steps_a)
	{
		rrm(a, b, 'a');
		steps_a--;
	}
	while (steps_b)
	{
		rm(a, b, 'b');
		steps_b--;
	}
}

void	push_to_a(t_stack **a, t_stack **b, int b_index)
{
	t_stack	*node;
	int		steps_a;
	int		steps_b;

	node = *b;
	while (node && node->index != b_index)
		node = node->next;
	steps_a = calculate_steps(*a, node->target_index);
	steps_b = calculate_steps(*b, b_index);
	if (node->target_index <= (stack_size(*a) - 1) / 2
		&& b_index <= (stack_size(*b) - 1) / 2)
		push_to_a_rr(a, b, steps_a, steps_b);
	else if (node->target_index > (stack_size(*a) - 1) / 2
		&& b_index > (stack_size(*b) - 1) / 2)
		push_to_a_rrr(a, b, steps_a, steps_b);
	else if (node->target_index <= (stack_size(*a) - 1) / 2
		&& b_index > (stack_size(*b) - 1) / 2)
		push_to_a_rmrrm(a, b, steps_a, steps_b);
	else
		push_to_a_rrmrm(a, b, steps_a, steps_b);
	pm(a, b, 'a');
}
