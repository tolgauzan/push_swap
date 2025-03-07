/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:18:41 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:18:41 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate(int *stack, int size)
{
	int	temp;
	int	i;

	temp = stack[0];
	i = 0;
	while (++i < size)
	{
		stack[i - 1] = stack[i];
	}
	stack[size - 1] = temp;
}

void	ra(t_stack *s)
{
	if (s->size_a > 1)
	{
		rotate(s->a, s->size_a);
		write(STDOUT_FILENO, "ra\n", 3);
	}
}

void	rb(t_stack *s)
{
	if (s->size_b > 1)
	{
		rotate(s->b, s->size_b);
		write(STDOUT_FILENO, "rb\n", 3);
	}
}
