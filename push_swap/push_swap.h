/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:19:13 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:19:13 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ASC 0
# define DESC 1

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

//Utils
void	free_exit(t_stack *s, char **args, int is_split, int is_error);
int		stack_has_duplicate(int *stack, int size);
int		safe_atoi(const char *str, t_stack *s, char **args, int is_split);
char	**free_split(char **split);
char	**ft_split(char const *s, char c);
//Operations
int		push_stack(t_stack *stack, int size, int flag);
void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size);
void	swap(int *first, int *second);
void	rotate(int *stack, int size);
void	reverse_rotate(int *stack, int size);
void	sa(t_stack *s);
void	pa(t_stack *s);
void	ra(t_stack *s);
void	rra(t_stack *s);
void	sb(t_stack *s);
void	pb(t_stack *s);
void	rb(t_stack *s);
void	rrb(t_stack *s);
//Sort
int		sort_case(t_stack *s);
void	sort_tempstack(int *tmp_stack, int size);
void	sort_two(t_stack *s, int is_stack_a);
void	sort_three_asc(t_stack *s);
int		is_sorted(int *stack, int size, int flag);
int		quicksort_a(t_stack *s, int size, int r_count);

#endif
