/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:40:45 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/16 16:40:51 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ADAPTIVE_SMALL_N 10

static void	sort_tiny(t_stack *a, t_stats *stats)
{
	if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
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

static int	sort_by_size(t_stack *a, t_stack *b, t_stats *stats)
{
	if (a->size <= 3)
	{
		sort_tiny(a, stats);
		return (1);
	}
	if (a->size <= ADAPTIVE_SMALL_N)
	{
		sort_simple(a, b, stats);
		return (1);
	}
	return (0);
}

int	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats)
{
	int	scaled;

	if (sort_by_size(a, b, stats))
		return (0);
	scaled = disorder_scaled(a);
	if (scaled < 2000)
	{
		sort_simple(a, b, stats);
		return (0);
	}
	else if (scaled < 5000)
	{
		sort_medium(a, b, stats);
		return (1);
	}
	else
	{
		sort_complex(a, b, stats);
		return (2);
	}
}
