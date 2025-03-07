/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:18:47 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:18:47 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	reverse_rotate(int *stack, int size)
{
	int	temp;
	int	i;

	temp = stack[size - 1];
	i = size;
	while (--i > 0)
	{
		stack[i] = stack[i - 1];
	}
	stack[0] = temp;
}

void	rra(t_stack *s)
{
	if (s->size_a > 1)
	{
		reverse_rotate(s->a, s->size_a);
		write(STDOUT_FILENO, "rra\n", 4);
	}
}

void	rrb(t_stack *s)
{
	if (s->size_b > 1)
	{
		reverse_rotate(s->b, s->size_b);
		write(STDOUT_FILENO, "rrb\n", 4);
	}
}
