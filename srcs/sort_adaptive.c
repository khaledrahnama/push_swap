/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:40:45 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/21 11:54:07 by semirkar         ###   ########.fr       */
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

static int	regime_of(int scaled)
{
	if (scaled < 2000)
		return (0);
	if (scaled < 5000)
		return (1);
	return (2);
}

int	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats)
{
	int	scaled;

	scaled = disorder_scaled(a);
	if (a->size <= 5)
	{
		sort_small(a, b, stats);
		return (regime_of(scaled));
	}
	if (scaled < 2000)
		sort_simple(a, b, stats);
	else if (scaled < 5000)
		sort_medium(a, b, stats);
	else
		sort_complex(a, b, stats);
	return (regime_of(scaled));
}
