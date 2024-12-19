/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:48:49 by marvin            #+#    #+#             */
/*   Updated: 2024/12/18 16:48:49 by marvin           ###   ########.fr       */
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

bool	is_valid_int(const char *str)
{
	long	value;
	int		sign;

	if (!str || !*str)
		return (false);
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
		if (*str < '0' || *str > '9')
			return (false);
		value = value * 10 + (*str - '0');
		if ((value * sign) < INT_MIN || (value * sign) > INT_MAX)
			return (false);
		str++;
	}
	return (true);
}

bool	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

t_stack *new_stack_node(int value, int index)
{
    t_stack *node = malloc(sizeof(t_stack));
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

void append_stack_node(t_stack **stack, t_stack *new_node)
{
    t_stack *temp;

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

void init_stack(t_stack **a, char **args)
{
    int     i;
    int     value;
    t_stack *node;

    i = 0;
    while (args[i])
    {
        if (!is_valid_int(args[i]))
		{
            write(2, "Error\n", 6);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
        value = ft_atoi(args[i]);
        if (has_duplicate(*a, value))
		{
            write(2, "Error\n", 6);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
        node = new_stack_node(value, i);
        if (!node)
		{
			free_stack(a);
			exit(EXIT_FAILURE);
		}
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

void    get_args(t_stack **a, int ac, char **av)
{
    int     i;
    char    *arg;
    char    **arr;

    arg = ft_strdup(av[1]); // MALLOC
    i = 2;
    while (i < ac)
    {
        arg = ft_strjoin(arg, av[i]); // MALLOC
        i++;
    }
    printf("args: %s\n", arg); // PRINTF
    arr = ft_split(arg, ' '); // MALLOC
    free(arg);
    init_stack(a, arr);
}

int main(int ac, char **av)
{
    int     i;
    t_stack *a;
    t_stack *b;

    i = 1;
    a = NULL;
    b = NULL;
    if (ac > 1)
    {
        get_args(&a, ac, av);
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
