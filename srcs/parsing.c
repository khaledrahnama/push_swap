/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/16 18:25:27 by khaledrahna      ###   ########.fr       */
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

static void	check_no_blank_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	has_content;

	i = 1;
	while (i < argc)
	{
		j = 0;
		has_content = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				has_content = 1;
			j++;
		}
		if (!has_content)
			error_exit();
		i++;
	}
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
	check_no_blank_args(argc, argv);
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
	if (a->size == 0)
		error_exit();
	free(joined);
}
