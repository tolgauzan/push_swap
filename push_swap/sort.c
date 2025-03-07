/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:19:32 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:19:32 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *s, int is_stack_a)
{
	if (is_stack_a && s->a[0] > s->a[1])
		sa(s);
	else if (!is_stack_a && s->b[0] < s->b[1])
		sb(s);
}

void	sort_three_asc(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		rra(s);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		ra(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s);
}

void	sort_tempstack(int *temp_stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp_stack[i] > temp_stack[j])
				swap(&temp_stack[i], &temp_stack[j]);
			j++;
		}
		i++;
	}
}

int	is_sorted(int *stack, int size, int flag)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (flag == ASC && stack[i] > stack[i + 1])
			return (0);
		if (flag == DESC && stack[i] < stack[i + 1])
			return (0);
	}
	return (1);
}

int	sort_case(t_stack *s)
{
	if (!is_sorted(s->a, s->size_a, ASC))
	{
		if (s->size_a == 2)
			sort_two(s, 1);
		else if (s->size_a == 3)
			sort_three_asc(s);
		else
		{
			if (!quicksort_a(s, s->size_a, 0))
				return (0);
		}
	}
	return (1);
}
