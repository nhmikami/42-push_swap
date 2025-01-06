/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:40:09 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:40:09 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	do_both(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(op, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	swap(t_stack **stack)
{
	t_stack	*head;

	if (!*stack || !(*stack)->next)
		return ;
	head = (*stack)->next;
	(*stack)->next = head->next;
	if (head->next)
		head->next->prev = *stack;
	head->prev = NULL;
	head->next = *stack;
	(*stack)->prev = head;
	*stack = head;
	return ;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	head = (*stack)->next;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	head->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	(*stack)->next = NULL;
	*stack = head;
	return ;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tail = *stack;
	last = NULL;
	while (tail->next)
	{
		last = tail;
		tail = tail->next;
	}
	last->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
	return ;
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	if (!stack_1 || !*stack_1)
		return ;
	temp = *stack_1;
	*stack_1 = (*stack_1)->next;
	if (*stack_1)
		(*stack_1)->prev = NULL;
	temp->next = *stack_2;
	if (*stack_2)
		(*stack_2)->prev = temp;
	*stack_2 = temp;
}
