/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:40:03 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:40:03 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

static int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	get_args(t_stack **a, int ac, char **av)
{
	int		i;
	char	*args;
	char	**arr;

	if (!check_args(ac, av))
		return (0);
	args = ft_strdup(av[1]);
	i = 2;
	while (i < ac)
	{
		args = ft_strjoin(args, " ");
		args = ft_strjoin(args, av[i]);
		i++;
	}
	if (!args)
		return (0);
	arr = ft_split(args, ' ');
	free(args);
	if (!init_stack(a, arr))
		return (0);
	return (1);
}
