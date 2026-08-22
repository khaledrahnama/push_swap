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

static int	already_seen(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	check_no_blank_args(int argc, char **argv)
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
		{
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}

static int	parse_one_number(char *joined, int *idx, t_stack *a)
{
	int	value;
	int	ok;

	value = (int)parse_number(joined, idx, &ok);
	if (!ok)
		return (0);
	if (joined[*idx] != ' ' && joined[*idx] != '\0')
	{
		print_error();
		return (0);
	}
	if (already_seen(a, value))
	{
		print_error();
		return (0);
	}
	a->data[a->size++] = value;
	return (1);
}

static int	parse_all_numbers(char *joined, t_stack *a)
{
	int	i;

	i = 0;
	while (joined[i])
	{
		while (joined[i] == ' ')
			i++;
		if (!joined[i])
			break ;
		if (!parse_one_number(joined, &i, a))
			return (0);
	}
	if (a->size == 0)
	{
		print_error();
		return (0);
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	*joined;

	if (argc < 2)
	{
		stack_init(a, 0);
		return (1);
	}
	if (!check_no_blank_args(argc, argv))
		return (0);
	joined = join_args(argc, argv);
	if (!joined)
		return (0);
	stack_init(a, ft_strlen(joined) + 1);
	if (!parse_all_numbers(joined, a))
	{
		free(joined);
		stack_free(a);
		return (0);
	}
	free(joined);
	return (1);
}
