/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:19:03 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:19:03 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	push_swap(int size, char **args, int is_split)
{
	t_stack	s;
	int		i;

	s.a = NULL;
	s.b = NULL;
	s.a = (int *)malloc(size * sizeof(int));
	s.b = (int *)malloc(size * sizeof(int));
	if (!s.a || !s.b)
		free_exit(&s, args, is_split, 1);
	s.size_a = size;
	s.size_b = 0;
	i = -1;
	while (++i < size)
		s.a[i] = safe_atoi(args[i], &s, args, is_split);
	if (stack_has_duplicate(s.a, s.size_a) || !sort_case(&s))
		free_exit(&s, args, is_split, 1);
	free_exit(&s, NULL, 0, 0);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		size;

	args = NULL;
	size = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], 32);
		if (!args || !args[0] || args[0][0] == '\0')
			free_exit(NULL, args, 1, 1);
		while (args[size])
			size++;
		push_swap(size, args, 1);
		free_split(args);
	}
	else if (argc > 2)
		push_swap(argc - 1, ++argv, 0);
	return (EXIT_SUCCESS);
}
