/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:19:47 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:19:47 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_exit(t_stack *s, char **args, int is_split, int is_error)
{
	if (args && is_split)
		free_split(args);
	if (s && s->a)
		free(s->a);
	if (s && s->b)
		free(s->b);
	if (is_error)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	safe_atoi(const char *str, t_stack *s, char **args, int is_split)
{
	unsigned long int	num;
	unsigned int		i;
	int					sign;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] >= 9 && str[i] <= 13)
		free_exit(s, args, is_split, 1);
	if (str[i] == '-')
		sign = -1;
	if (((str[i] == '-' || str[i] == '+') && !(str[++i] >= '0'
				&& str[i] <= '9')) || (str[i] == '0' && str[++i] != '\0'))
		free_exit(s, args, is_split, 1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			free_exit(s, args, is_split, 1);
		num = (str[i] - '0') + (num * 10);
		if ((sign == -1 && num > 2147483648) || (sign == 1 && num > 2147483647))
			free_exit(s, args, is_split, 1);
		i++;
	}
	return ((int)num * sign);
}

int	stack_has_duplicate(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
