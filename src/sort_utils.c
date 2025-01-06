/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:39:53 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:39:53 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	find_index(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

int	calculate_steps(t_stack *stack, int index)
{
	int	steps;

	if (index <= (stack_size(stack) - 1) / 2)
		steps = index;
	else
		steps = stack_size(stack) - index;
	return (steps);
}

void	handle_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
