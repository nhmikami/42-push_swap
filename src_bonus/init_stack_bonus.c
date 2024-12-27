#include "../include/checker.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

static t_stack	*new_stack_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	append_stack_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	temp = *stack;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	init_stack(t_stack **a, char **args)
{
	int		i;
	int		value;
	t_stack	*node;

	i = 0;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		if (!is_valid_int(args[i]) || !check_duplicate(*a, value))
		{
			write(2, "Error\n", 6);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
		node = new_stack_node(value);
		append_stack_node(a, node);
		i++;
	}
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
