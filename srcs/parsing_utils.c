/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

static int	total_len_of(int argc, char **argv)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 1;
	while (i < argc)
		total_len += ft_strlen(argv[i++]) + 1;
	return (total_len);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	int		i;
	int		pos;
	int		j;

	joined = malloc(sizeof(char) * (total_len_of(argc, argv) + 1));
	if (!joined)
	{
		print_error();
		return (NULL);
	}
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

static int	parse_sign(char *str, int *idx)
{
	int	sign;

	sign = 1;
	if (str[*idx] == '-' || str[*idx] == '+')
	{
		if (str[*idx] == '-')
			sign = -1;
		(*idx)++;
	}
	return (sign);
}

long	parse_number(char *str, int *idx, int *ok)
{
	long	value;
	int		sign;

	value = 0;
	*ok = 0;
	sign = parse_sign(str, idx);
	while (ft_isdigit(str[*idx]))
	{
		value = value * 10 + (str[*idx] - '0');
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value > (long)INT_MAX + 1))
		{
			*ok = 0;
			print_error();
			return (0);
		}
		*ok = 1;
		(*idx)++;
	}
	if (!*ok)
		print_error();
	return (value * sign);
}
