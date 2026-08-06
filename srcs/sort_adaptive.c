/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:33:42 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/06 13:43:54 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats)
{
	int	scaled;

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
