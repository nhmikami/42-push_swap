/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:46:25 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:46:25 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	lowest_to_top(t_stack **a, t_stack **b)
{
	t_stack	*trav;
	int		value;
	int		index;
	int		steps;

	value = INT_MAX;
	trav = *a;
	while (trav)
	{
		if (trav->value < value)
			value = trav->value;
		trav = trav->next;
	}
	index = find_index(*a, value);
	steps = calculate_steps(*a, index) + 1;
	if (index <= (stack_size(*a) - 1) / 2)
		while (--steps)
			rm(a, b, 'a');
	else
		while (--steps)
			rrm(a, b, 'a');
}

static void	small_sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		sm(a, b, 'a');
	else
	{
		if ((*a)->value < (*a)->next->value)
		{
			rrm(a, b, 'a');
			if ((*a)->value > (*a)->next->value)
				sm(a, b, 'a');
		}
		else
		{
			if ((*a)->value < (*a)->next->next->value)
				sm(a, b, 'a');
			else
			{
				rm(a, b, 'a');
				if ((*a)->value > (*a)->next->value)
					sm(a, b, 'a');
			}
		}
	}
}

static void	big_sort(t_stack **a, t_stack **b)
{
	int	index;

	if (stack_size(*a) > 3 && !is_sorted(*a))
		pm(a, b, 'b');
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pm(a, b, 'b');
	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		calculate_cost_a(*a, *b);
		index = find_cheaper(*a);
		push_to_b(a, b, index);
	}
	if (!is_sorted(*a))
		small_sort(a, b);
	while (stack_size(*b) > 0)
	{
		calculate_cost_b(*a, *b);
		index = find_cheaper(*b);
		push_to_a(a, b, index);
	}
	if (!is_sorted(*a))
		lowest_to_top(a, b);
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
			handle_error(&a, &b);
		if (!is_sorted(a))
		{
			if (stack_size(a) <= 3)
				small_sort(&a, &b);
			else
				big_sort(&a, &b);
		}
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
