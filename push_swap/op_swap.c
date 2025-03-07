/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:18:52 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:18:52 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	sa(t_stack *s)
{
	if (s->size_a > 1)
	{
		swap(&s->a[0], &s->a[1]);
		write(STDOUT_FILENO, "sa\n", 3);
	}
}

void	sb(t_stack *s)
{
	if (s->size_b > 1)
	{
		swap(&s->b[0], &s->b[1]);
		write(STDOUT_FILENO, "sb\n", 3);
	}
}
