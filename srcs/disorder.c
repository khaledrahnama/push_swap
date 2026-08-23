/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/22 17:37:56 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_mistakes(t_stack *a)
{
	long	mistakes;
	int		i;
	int		j;

	mistakes = 0;
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->data[i] > a->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

int	stack_is_sorted(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->size)
	{
		if (a->data[i - 1] > a->data[i])
			return (0);
		i++;
	}
	return (1);
}

static long	total_pairs(int n)
{
	if (n < 2)
		return (0);
	return ((long)n * (n - 1) / 2);
}

int	disorder_scaled(t_stack *a)
{
	long	mistakes;
	long	pairs;

	pairs = total_pairs(a->size);
	if (pairs == 0)
		return (0);
	mistakes = count_mistakes(a);
	return ((int)(mistakes * 10000 / pairs));
}

void	print_disorder_pct(int scaled, int fd)
{
	ft_putnbr_fd(scaled / 100, fd);
	ft_putstr_fd(".", fd);
	if (scaled % 100 < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(scaled % 100, fd);
	ft_putstr_fd("%", fd);
}
