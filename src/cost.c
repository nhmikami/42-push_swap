/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:38:47 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:38:47 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_cheaper(t_stack *stack)
{
	int	cost;
	int	index;

	cost = stack->cost;
	index = stack->index;
	while (stack)
	{
		if (stack->cost < cost)
		{
			cost = stack->cost;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

static int	define_target_b(t_stack *b, int value)
{
	int		aux;
	int		max;
	int		flag;
	t_stack	*trav;

	trav = b;
	aux = INT_MIN;
	max = trav->value;
	flag = 0;
	while (trav)
	{
		if (trav->value < value)
		{
			if (!flag || trav->value > aux)
				aux = trav->value;
			flag = 1;
		}
		if (trav->value > max)
			max = trav->value;
		trav = trav->next;
	}
	if (flag)
		return (aux);
	else
		return (max);
}

static int	define_target_a(t_stack *a, int value)
{
	int		aux;
	int		min;
	int		flag;
	t_stack	*trav;

	trav = a;
	aux = INT_MAX;
	min = trav->value;
	flag = 0;
	while (trav)
	{
		if (trav->value > value)
		{
			if (!flag || trav->value < aux)
				aux = trav->value;
			flag = 1;
		}
		if (trav->value < min)
			min = trav->value;
		trav = trav->next;
	}
	if (flag)
		return (aux);
	else
		return (min);
}

void	calculate_cost_a(t_stack *a, t_stack *b)
{
	t_stack	*trav;

	trav = a;
	while (trav)
	{
		trav->target_value = define_target_b(b, trav->value);
		trav->target_index = find_index(b, trav->target_value);
		if (trav->index <= (stack_size(a) - 1) / 2
			&& trav->target_index <= (stack_size(b) - 1) / 2)
			trav->cost = ft_greater(trav->index, trav->target_index);
		else if (trav->index > (stack_size(a) - 1) / 2
			&& trav->target_index > (stack_size(b) - 1) / 2)
			trav->cost = ft_greater(stack_size(a) - trav->index, stack_size(b)
					- trav->target_index);
		else if (trav->index <= (stack_size(a) - 1) / 2
			&& trav->target_index > (stack_size(b) - 1) / 2)
			trav->cost = trav->index + stack_size(b) - trav->target_index;
		else
			trav->cost = stack_size(a) - trav->index + trav->target_index;
		trav = trav->next;
	}
}

void	calculate_cost_b(t_stack *a, t_stack *b)
{
	t_stack	*trav;

	trav = b;
	while (trav)
	{
		trav->target_value = define_target_a(a, trav->value);
		trav->target_index = find_index(a, trav->target_value);
		if (trav->index <= (stack_size(b) - 1) / 2
			&& trav->target_index <= (stack_size(a) - 1) / 2)
			trav->cost = ft_greater(trav->index, trav->target_index);
		else if (trav->index > (stack_size(b) - 1) / 2
			&& trav->target_index > (stack_size(a) - 1) / 2)
			trav->cost = ft_greater(stack_size(b) - trav->index, stack_size(a)
					- trav->target_index);
		else if (trav->index <= (stack_size(b) - 1) / 2
			&& trav->target_index > (stack_size(a) - 1) / 2)
			trav->cost = trav->index + stack_size(a) - trav->target_index;
		else
			trav->cost = stack_size(b) - trav->index + trav->target_index;
		trav = trav->next;
	}
}
