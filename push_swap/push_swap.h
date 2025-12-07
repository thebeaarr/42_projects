/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:38:01 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 18:50:19 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Stack node structure
typedef struct node
{
	int			i;
	int			index;
	struct node	*next;
	struct node	*prev;
}				t_node;

// Stack structure
typedef struct stack
{
	t_node		*head;
	t_node		*tail;
}				t_stack;

// Other structs
typedef struct s_range_vars
{
	int	div;
	int	mid;
	int	offset;
	int	start;
	int	end;
}	t_range_vars;

typedef struct s_n
{
	t_node	*a;
	t_stack	*s;
	int		i;
	t_node	*tmp;	
}	t_n;

typedef struct s_max_vars
{
	int	max;
	int	max_pos;
	int	max_less;
	int	max_less_pos;
	int	cost_max;
	int	cost_max_less;
}	t_max_vars;

typedef struct s_data
{
	int	k;
	int	*ar;
	int	size;
	int	*sorted_ar;
}	t_data;

void			message(void);
void			bubble_sort(int *arr, int size);
int				*sorted(int *a, int size);
size_t			ft_strlen(const char *s);
int				is_sorted(int *a, int k);
char			*join(int ac, char **av, size_t size);
void			da7k(char *string, int *i);
void			replace_by_space(char *str);
void			check(char *str);
void			handle_overflow(int *a, char *b);
int				*parse_input(int ac, char **av, int *k);
void			check_for_duplicates(int *array, int size);
void			parse_numbers(char *input, int *arr);
long			extract_number(char *input, int *i, int *arr, int sign);
void			is_here_dup(int *a, int k);
void			sort_2(t_stack *a);
void			sort_3(t_stack *a);
void			sort_5(t_stack *a, t_stack *b);
int				find_best_top(t_stack *s, int low_val, int high_val);
int				find_best_bot(t_stack *s, int low_val, int high_val, int size);
void			handle_push_and_rotate(t_stack *stacka, t_stack *stackb,
					t_max_vars *vars, int *flag);
void			push_max_to_stacka(t_stack *stacka, t_stack *stackb);
void			big_sort(t_stack *stacka, t_stack *stackb, int *sorted_arr,
					int size);
void			handle_rotate_a(t_stack *stack, int pos, int size);
void			process_input(int ac, char **av, int *k, int **ar);
void			handle_error(int *ar, t_stack *stacka, t_stack *stackb);
void			handle_rotate_b(t_stack *stack, int pos, int size);
void			check_and_swap(t_stack *stacka);
void			rotate_to_position(t_stack *stack, int pos, int size, char a);
int				nichan(int best_top, int best_bot, int size);
void			find_max(t_stack *stackb, t_max_vars *vars);
void			find_max_less(t_stack *stackb, t_max_vars *vars);
void			update_costs(t_max_vars *vars, int size_b);
void			update_range_bounds(t_range_vars *r, int size);
void			push_to_stackb(t_stack *stacka, t_stack *stackb,
					int *sorted_arr, t_range_vars *r);
void			push_range_to_stackb(t_stack *stacka, t_stack *stackb,
					int *sorted_arr, int size);
int				get_best_pos_in_range(t_stack *s, int low_val, int high_val);
void			init_range_vars(t_range_vars *r, int size);
void			rotate(t_stack *stack);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			reverse_rotate(t_stack *stack);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			swap(t_stack *stack);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			push(t_stack *from, t_stack *to);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
int				stack_size(t_stack *stack);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);
t_stack			*fill_stack(int *arr, int k);
void			free_stack(t_stack *stack);
t_stack			*initialize_stack(void);
void			afficher_stack(t_stack *a);
void			clean_exit(t_stack *stacka, t_stack *stackb, char *f);
int				khdma(char *f, t_stack *a, t_stack *b);
int				compare(char *f, char *op);
int				sorted_check(t_stack *a, t_stack *b);
t_stack			*setup_stacks(int ac, char **av, t_stack *stacka);
void			execute_operations(t_stack *stacka, t_stack *stackb);

#endif