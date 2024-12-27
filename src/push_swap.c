/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:48:49 by naharumi          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:00 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_a(t_stack **a, t_stack **b)
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
		sort_a(a, b);
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

// cc src/*.c libft/libft/*.c

	/*printf("stack a:\n");
	while (a)
	{
		printf("Value: %d, index: %d, cost: %d\n", a->value, a->index, a->cost);
		a = a->next;
	}
	printf("stack b:\n");
	while (b)
	{
		printf("Value: %d, index: %d, cost: %d\n", b->value, b->index, b->cost);
		b = b->next;
	}*/
