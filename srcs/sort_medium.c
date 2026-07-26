/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:38:49 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/26 15:38:53 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sweep_chunk(t_stack *a, t_stack *b, int cmin, int cmax)
{
	int	sweep_count;
	int	i;

	sweep_count = a->size;
	i = 0;
	while (i < sweep_count)
	{
		if (a->data[0] >= cmin && a->data[0] <= cmax)
			op_pb(a, b, 1);
		else
			op_ra(a, 1);
		i++;
	}
}

static void	insert_fixup(t_stack *a)
{
	while (a->size >= 2 && a->data[0] > a->data[1])
	{
		op_sa(a, 1);
		op_ra(a, 1);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	n;
	int	*sorted;
	int	chunk_size;
	int	num_chunks;
	int	c;
	int	hi_i;

	n = a->size;
	if (n < 2)
		return ;
	sorted = malloc(sizeof(int) * n);
	if (!sorted)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	copy_ints(sorted, a->data, n);
	sort_ints(sorted, n);
	chunk_size = int_sqrt(n);
	if (chunk_size < 1)
		chunk_size = 1;
	num_chunks = (n + chunk_size - 1) / chunk_size;
	c = 0;
	while (c < num_chunks)
	{
		hi_i = (c + 1) * chunk_size - 1;
		if (hi_i > n - 1)
			hi_i = n - 1;
		sweep_chunk(a, b, sorted[c * chunk_size], sorted[hi_i]);
		c++;
	}
	free(sorted);
	while (b->size > 0)
	{
		op_pa(a, b, 1);
		insert_fixup(a);
	}
}