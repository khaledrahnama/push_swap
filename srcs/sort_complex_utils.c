/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/21 11:54:11 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_ints(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

int	*build_sorted_copy(t_stack *a)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (i < a->size)
	{
		sorted[i] = a->data[i];
		i++;
	}
	sort_ints(sorted, a->size);
	return (sorted);
}

int	rank_of(int value, int *sorted, int n)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (sorted[mid] == value)
			return (mid);
		else if (sorted[mid] < value)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (-1);
}

int	nbits_for(int n)
{
	int	b;

	b = 0;
	while ((1 << b) < n)
		b++;
	if (b < 1)
		b = 1;
	return (b);
}
