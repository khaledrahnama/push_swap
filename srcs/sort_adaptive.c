/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:42:45 by semirkar          #+#    #+#             */
/*   Updated: 2026/08/25 21:42:47 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tiny(t_stack *a, t_stats *stats)
{
	if (stack_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		op_sa(a, 1, stats);
		return ;
	}
	if (a->data[0] < a->data[2] && a->data[2] < a->data[1])
	{
		op_sa(a, 1, stats);
		op_ra(a, 1, stats);
	}
	else if (a->data[1] < a->data[0] && a->data[0] < a->data[2])
		op_sa(a, 1, stats);
	else if (a->data[1] < a->data[2] && a->data[2] < a->data[0])
		op_ra(a, 1, stats);
	else if (a->data[2] < a->data[0] && a->data[0] < a->data[1])
		op_rra(a, 1, stats);
	else
	{
		op_sa(a, 1, stats);
		op_rra(a, 1, stats);
	}
}

static void	sort_small(t_stack *a, t_stack *b, t_stats *stats)
{
	if (a->size < 2)
		return ;
	while (a->size > 3)
	{
		rotate_to_top(a, find_min_index(a), stats);
		op_pb(a, b, 1, stats);
	}
	sort_tiny(a, stats);
	while (b->size > 0)
		op_pa(a, b, 1, stats);
}

static int	regime_method(double disorder)
{
	if (disorder < LOW_DISORDER)
		return (METHOD_SIMPLE);
	if (disorder < HIGH_DISORDER)
		return (METHOD_MEDIUM);
	return (METHOD_COMPLEX);
}

int	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats)
{
	double	disorder;

	disorder = disorder_of(a);
	if (a->size <= SMALL_STACK_MAX)
	{
		sort_small(a, b, stats);
		return (METHOD_SMALL);
	}
	if (disorder < LOW_DISORDER)
		sort_simple(a, b, stats);
	else if (disorder < HIGH_DISORDER)
		sort_medium(a, b, stats);
	else
		sort_complex(a, b, stats);
	return (regime_method(disorder));
}
