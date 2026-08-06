/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:32:29 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/06 23:49:40 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sweep_chunk(t_stack *a, t_stack *b, t_chunk *chunk,
		t_stats *stats)
{
	int	sweep_count;
	int	i;

	sweep_count = a->size;
	i = 0;
	while (i < sweep_count)
	{
		if (a->data[0] >= chunk->min && a->data[0] <= chunk->max)
			op_pb(a, b, 1, stats);
		else
			op_ra(a, 1, stats);
		i++;
	}
}

static int	find_max_index(t_stack *b)
{
	int	max_idx;
	int	i;

	max_idx = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->data[i] > b->data[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

static void	rotate_b_to_top(t_stack *b, int index, t_stats *stats)
{
	int	steps_up;
	int	steps_down;

	steps_up = index;
	steps_down = b->size - index;
	if (steps_up <= steps_down)
	{
		while (steps_up-- > 0)
			op_rb(b, 1, stats);
	}
	else
	{
		while (steps_down-- > 0)
			op_rrb(b, 1, stats);
	}
}

static void	drain_max_to_a(t_stack *a, t_stack *b, t_stats *stats)
{
	int	max_idx;

	while (b->size > 0)
	{
		max_idx = find_max_index(b);
		rotate_b_to_top(b, max_idx, stats);
		op_pa(a, b, 1, stats);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_stats *stats)
{
	t_chunk_plan	plan;
	t_chunk			chunk;
	int				c;

	if (a->size < 2)
		return ;
	build_chunk_plan(a, &plan);
	c = plan.num_chunks - 1;
	while (c >= 0)
	{
		get_chunk_bounds(&plan, c, &chunk);
		sweep_chunk(a, b, &chunk, stats);
		drain_max_to_a(a, b, stats);
		c--;
	}
	free(plan.sorted);
}