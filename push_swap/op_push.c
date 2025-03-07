/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:18:33 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:18:33 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size)
{
	int	i;

	(*dst_size)++;
	i = *dst_size;
	while (--i > 0)
		dst_stack[i] = dst_stack[i - 1];
	dst_stack[0] = src_stack[0];
	(*src_size)--;
	i = -1;
	while (++i < *src_size)
		src_stack[i] = src_stack[i + 1];
}

void	pa(t_stack *s)
{
	if (s->size_b > 0)
	{
		push(s->b, s->a, &s->size_b, &s->size_a);
		write(STDOUT_FILENO, "pa\n", 3);
	}
}

void	pb(t_stack *s)
{
	if (s->size_a > 0)
	{
		push(s->a, s->b, &s->size_a, &s->size_b);
		write(STDOUT_FILENO, "pb\n", 3);
	}
}

int	push_stack(t_stack *stack, int size, int flag)
{
	if (flag)
		pa(stack);
	else
		pb(stack);
	return (size - 1);
}
