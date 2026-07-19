/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:32:27 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/19 16:35:08 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	int	min_idx;
	int	i;

	min_idx = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->data[i] < a->data[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	rotate_to_top(t_stack *a, int index)
{
	int	steps_up;
	int	steps_down;

	steps_up = index;
	steps_down = a->size - index;
	if (steps_up <= steps_down)
	{
		while (steps_up-- > 0)
			op_ra(a, 1);
	}
	else
	{
		while (steps_down-- > 0)
			op_rra(a, 1);
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	int	min_idx;

	while (a->size > 0)
	{
		min_idx = find_min_index(a);
		rotate_to_top(a, min_idx);
		op_pb(a, b, 1);
	}
	while (b->size > 0)
		op_pa(a, b, 1);
}