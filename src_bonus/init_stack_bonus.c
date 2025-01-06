/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:40:06 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:40:06 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	free_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
	return ;
}

int	init_stack(t_stack **a, char **args)
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
			free_arr(args);
			return (0);
		}
		node = new_stack_node(value);
		append_stack_node(a, node);
		i++;
	}
	free_arr(args);
	return (1);
}
