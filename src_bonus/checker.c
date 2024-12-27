#include "../include/checker.h"

void	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		do_both(a, b, op);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		do_both(a, b, op);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		do_both(a, b, op);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push(a, b);
	else
		handle_error(a, b);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		execute_operation(a, b, op);
		free(op);
		op = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (!get_args(&a, ac, av))
			return (1);
		checker(&a, &b);
		if (is_sorted(a) && stack_size(b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
