/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:43:10 by semirkar          #+#    #+#             */
/*   Updated: 2026/08/25 21:43:16 by semirkar         ###   ########.fr       */
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

double	disorder_of(t_stack *a)
{
	long	pairs;

	pairs = total_pairs(a->size);
	if (pairs == 0)
		return (0.0);
	return ((double)count_mistakes(a) / (double)pairs);
}

void	print_disorder_pct(double disorder, int fd)
{
	long	hundredths;

	hundredths = (long)(disorder * 10000.0 + 0.5);
	ft_putnbr_fd(hundredths / 100, fd);
	ft_putstr_fd(".", fd);
	if (hundredths % 100 < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(hundredths % 100, fd);
	ft_putstr_fd("%", fd);
}
