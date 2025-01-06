/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:38:08 by naharumi          #+#    #+#             */
/*   Updated: 2025/01/06 14:38:08 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// get arguments
int		get_args(t_stack **a, int ac, char **av);
int		is_valid_int(const char *str);
int		check_duplicate(t_stack *stack, int value);

// initialize stack
int		init_stack(t_stack **a, char **args);
void	free_stack(t_stack **stack);

// operations
void	swap(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	do_both(t_stack **a, t_stack **b, char *op);

// utils
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	handle_error(t_stack **a, t_stack **b);

#endif