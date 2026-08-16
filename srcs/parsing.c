/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_one_number(char *joined, int *idx, t_stack *a)
{
	int	value;

	value = (int)parse_number(joined, idx);
	if (joined[*idx] != ' ' && joined[*idx] != '\0')
		error_exit();
	if (already_seen(a, value))
		error_exit();
	a->data[a->size++] = value;
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	char	*joined;
	int		i;

	if (argc < 2)
	{
		stack_init(a, 0);
		return ;
	}
	joined = join_args(argc, argv);
	stack_init(a, ft_strlen(joined) + 1);
	i = 0;
	while (joined[i])
	{
		while (joined[i] == ' ')
			i++;
		if (!joined[i])
			break ;
		parse_one_number(joined, &i, a);
	}
	free(joined);
}
