#include "../include/push_swap.h"

static void	update_index(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
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
	update_index(*stack);
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
	update_index(*stack);
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
	update_index(*stack);
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
	update_index(*stack_1);
	update_index(*stack_2);
}
