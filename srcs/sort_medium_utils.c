/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/21 11:54:16 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

void	copy_ints(int *dst, int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	sort_ints_med(int *arr, int n)
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

void	build_chunk_plan(t_stack *a, t_chunk_plan *plan)
{
	plan->n = a->size;
	plan->sorted = malloc(sizeof(int) * plan->n);
	if (!plan->sorted)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	copy_ints(plan->sorted, a->data, plan->n);
	sort_ints_med(plan->sorted, plan->n);
	plan->chunk_size = (int_sqrt(plan->n) * 7) / 2;
	if (plan->chunk_size < 1)
		plan->chunk_size = 1;
	plan->num_chunks = (plan->n + plan->chunk_size - 1) / plan->chunk_size;
}

void	get_chunk_bounds(t_chunk_plan *plan, int c, t_chunk *chunk)
{
	int	hi_i;

	hi_i = (c + 1) * plan->chunk_size - 1;
	if (hi_i > plan->n - 1)
		hi_i = plan->n - 1;
	chunk->min = plan->sorted[c * plan->chunk_size];
	chunk->max = plan->sorted[hi_i];
}
