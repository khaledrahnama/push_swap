/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/21 11:54:34 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_mistakes(t_stack *a)
{
	int	i;
	int	j;
	int	mistakes;

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

int	total_pairs(int n)
{
	if (n < 2)
		return (0);
	return ((n * (n - 1)) / 2);
}

int	disorder_scaled(t_stack *a)
{
	int	mistakes;
	int	pairs;

	pairs = total_pairs(a->size);
	if (pairs == 0)
		return (0);
	mistakes = count_mistakes(a);
	return ((mistakes * 10000) / pairs);
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
