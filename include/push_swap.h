/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:09:37 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 16:30:34 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /// APAGAR
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				target_value;
	int				target_index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// get arguments
int		get_args(t_stack **a, int ac, char **av);
int		is_valid_int(const char *str);
int		check_duplicate(t_stack *stack, int value);

// initialize stack
void	init_stack(t_stack **a, char **args);
void	free_stack(t_stack **stack);

// operations
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);

// commands
void	sm(t_stack **a, t_stack **b, char c);
void	rm(t_stack **a, t_stack **b, char c);
void	rrm(t_stack **a, t_stack **b, char c);
void	pm(t_stack **a, t_stack **b, char c);

// solve
int		ft_greater(int num1, int num2);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
int		find_index(t_stack *stack, int value);
int		find_cheaper(t_stack *stack);
int		calculate_steps(t_stack *stack, int index);
void	calculate_cost_a(t_stack *a, t_stack *b);
void	calculate_cost_b(t_stack *a, t_stack *b);
void	push_to_a(t_stack **a, t_stack **b, int b_index);
void	push_to_b(t_stack **a, t_stack **b, int a_index);

#endif
