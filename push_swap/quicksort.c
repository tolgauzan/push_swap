/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:19:23 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:19:23 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	get_median(int *stack, int size, int *pivot)
{
	int	*tmp_sorted;
	int	i;

	tmp_sorted = (int *)malloc(sizeof(int) * size);
	if (!tmp_sorted)
		return (0);
	i = -1;
	while (++i < size)
		tmp_sorted[i] = stack[i];
	sort_tempstack(tmp_sorted, size);
	*pivot = tmp_sorted[size / 2];
	free(tmp_sorted);
	tmp_sorted = NULL;
	return (1);
}

static int	quicksort_small_b(t_stack *s, int size)
{
	if (size == 2)
	{
		sort_two(s, 0);
		pa(s);
		pa(s);
	}
	else if (size == 3)
	{
		while (size != 0 || !is_sorted(s->a, 3, ASC))
		{
			if (size == 1 && s->a[0] > s->a[1])
				sa(s);
			else if (size == 1
				|| (size >= 2 && s->b[0] > s->b[1])
				|| (size == 3 && s->b[0] > s->b[2]))
				size = push_stack(s, size, 1);
			else
				sb(s);
		}
	}
	return (1);
}

static int	quicksort_small_a(t_stack *s, int size)
{
	if (size == 3 && s->size_a == 3)
		sort_three_asc(s);
	else if (size == 2)
		sort_two(s, 1);
	else if (size == 3)
	{
		while (size != 3 || !is_sorted(s->a, 3, ASC))
		{
			if (size == 3 && s->a[0] > s->a[1] && s->a[2])
				sa(s);
			else if (size == 3
				&& !(s->a[2] > s->a[0]
					&& s->a[2] > s->a[1]))
				size = push_stack(s, size, 0);
			else if (s->a[0] > s->a[1])
				sa(s);
			else if (size++)
				pa(s);
		}
	}
	return (1);
}

static int	quicksort_b(t_stack *s, int size, int r_count)
{
	int	pivot;
	int	total;

	total = size;
	if (!r_count && is_sorted(s->b, size, DESC))
	{
		while (size--)
			pa(s);
		return (1);
	}
	if (size <= 3)
		return (quicksort_small_b(s, size));
	if (!get_median(s->b, size, &pivot))
		return (0);
	while (size != total / 2)
	{
		if (s->b[0] >= pivot && (size--))
			pa(s);
		else if (++r_count)
			rb(s);
	}
	while (total / 2 != s->size_b && r_count--)
		rrb(s);
	return (quicksort_a(s, total / 2 + total % 2, 0)
		&& quicksort_b(s, total / 2, 0));
}

int	quicksort_a(t_stack *s, int size, int r_count)
{
	int	pivot;
	int	total;

	total = size;
	if (is_sorted(s->a, size, ASC))
		return (1);
	if (size <= 3)
		return (quicksort_small_a(s, size));
	if (!get_median(s->a, size, &pivot))
		return (0);
	while (size != total / 2 + total % 2)
	{
		if (s->a[0] < pivot && (size--))
			pb(s);
		else if (++r_count)
			ra(s);
	}
	while (total / 2 + total % 2 != s->size_a && r_count--)
		rra(s);
	return (quicksort_a(s, total / 2 + total % 2, 0)
		&& quicksort_b(s, total / 2, 0));
}
