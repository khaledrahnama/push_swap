/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:34:54 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/19 12:34:57 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static char	*join_args(int argc, char **argv)
{
	char	*joined;
	int		total_len;
	int		i;
	int		pos;
	int		j;

	total_len = 0;
	i = 1;
	while (i < argc)
		total_len += ft_strlen(argv[i++]) + 1;
	joined = malloc(sizeof(char) * (total_len + 1));
	if (!joined)
		error_exit();
	pos = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			joined[pos++] = argv[i][j++];
		joined[pos++] = ' ';
		i++;
	}
	joined[pos] = '\0';
	return (joined);
}

static long	parse_number(char *str, int *idx)
{
	long	value;
	int		sign;
	int		has_digit;

	sign = 1;
	value = 0;
	has_digit = 0;
	if (str[*idx] == '-' || str[*idx] == '+')
	{
		if (str[*idx] == '-')
			sign = -1;
		(*idx)++;
	}
	while (ft_isdigit(str[*idx]))
	{
		value = value * 10 + (str[*idx] - '0');
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value > (long)INT_MAX + 1))
			error_exit();
		has_digit = 1;
		(*idx)++;
	}
	if (!has_digit)
		error_exit();
	return (value * sign);
}

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

void	parse_args(int argc, char **argv, t_stack *a)
{
	char	*joined;
	int		i;
	int		value;

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
		value = (int)parse_number(joined, &i);
		if (joined[i] != ' ' && joined[i] != '\0')
			error_exit();
		if (already_seen(a, value))
			error_exit();
		a->data[a->size++] = value;
	}
	free(joined);
}