/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:34:54 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/06 23:49:54 by khaledrahna      ###   ########.fr       */
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