/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:48:49 by naharumi          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:00 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

t_stack	*new_stack_node(int value, int index)
{
	t_stack	*node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->cost = 0;
	node->target_value = 0;
	node->target_index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	append_stack_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	temp = *stack;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

// check args
int	is_valid_int(const char *str)
{
	long	value;
	int		sign;

	if (!str || !*str)
		return (0);
	sign = 1;
	value = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (false);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		value = value * 10 + (*str - '0');
		if ((value * sign) < INT_MIN || (value * sign) > INT_MAX)
			return (0);
		str++;
	}
	return (1);
}

int	check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->next;
	}
	return (1);
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
			write(1, "Error\n", 6);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
		node = new_stack_node(value, i);
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

int	get_args(t_stack **a, int ac, char **av)
{
	int		i;
	char	*args;
	char	**arr;

	args = ft_strdup(av[1]); // MALLOC
	i = 2;
	while (i < ac)
	{
		args = ft_strjoin(args, av[i]); // MALLOC
		i++;
	}
	if (!args)
		return (0);
	// printf("args: %s\n", args); // PRINTF
	arr = ft_split(args, ' '); // MALLOC
	free(args);
	init_stack(a, arr);
	return (1);
}

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

// operations
t_stack	*swap(t_stack *stack)
{
	t_stack	*head;

	if (!stack || !stack->next)
		return (stack);
	head = stack->next;
	stack->next = head->next;
	if (head->next)
	{
		head->next->prev = stack;
	}
	head->prev = NULL;
	head->next = stack;
	stack->prev = head;
	stack->index = 1;
	head->index = 0;
	return (head);
}

t_stack	*rotate(t_stack *stack)
{
	t_stack *head;
	t_stack *new_head;
	t_stack *tail;

	if (!stack || !stack->next)
		return (stack);
	head = stack;
	new_head = stack->next;
	tail = stack;
	while (tail->next)
	{
		tail = tail->next;
		tail->index = tail->index - 1;
	}
	new_head->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	head->index = head->prev->index + 1;
	return (new_head);
}

t_stack	*reverse_rotate(t_stack *stack) {
    if (!stack || !stack->next)
        return stack;

    t_stack *tail = stack;
    t_stack *second_to_last = NULL;

    while (tail->next) {
        second_to_last = tail;
        tail = tail->next;
    }

    second_to_last->next = NULL; // Second-to-last node becomes the last node
    tail->prev = NULL;          // Last node becomes the new head
    tail->next = stack;         // Last node's next points to the original head
    stack->prev = tail;         // Original head's previous points to the new head

    return tail;                // Return the new head
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
			{
				printf("sort three\n");
				a = rotate(a);
				// sort_three
			}
			else
			{
				printf("sort big\n");
				// sort
			}
		}
	}
	while (a)
	{
		printf("Value: %d, index: %d\n", a->value, a->index);
		a = a->next;
	}
	free_stack(&a);
	return (0);
}

// cc main.c libft/*.c
