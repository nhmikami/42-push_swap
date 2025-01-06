/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:39:49 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:39:49 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_to_b_rr(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

static void	push_to_b_rrr(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

static void	push_to_b_rmrrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

static void	push_to_b_rrmrm(t_stack **a, t_stack **b, int steps_a, int steps_b)
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

void	push_to_b(t_stack **a, t_stack **b, int a_index)
{
	t_stack	*node;
	int		steps_a;
	int		steps_b;

	node = *a;
	while (node && node->index != a_index)
		node = node->next;
	steps_a = calculate_steps(*a, a_index);
	steps_b = calculate_steps(*b, node->target_index);
	if (a_index <= (stack_size(*a) - 1) / 2
		&& node->target_index <= (stack_size(*b) - 1) / 2)
		push_to_b_rr(a, b, steps_a, steps_b);
	else if (a_index > (stack_size(*a) - 1) / 2
		&& node->target_index > (stack_size(*b) - 1) / 2)
		push_to_b_rrr(a, b, steps_a, steps_b);
	else if (a_index <= (stack_size(*a) - 1) / 2
		&& node->target_index > (stack_size(*b) - 1) / 2)
		push_to_b_rmrrm(a, b, steps_a, steps_b);
	else
		push_to_b_rrmrm(a, b, steps_a, steps_b);
	pm(a, b, 'b');
}
