/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_stack *a, int print, t_stats *stats)
{
	int	last;
	int	i;

	if (a->size >= 2)
	{
		last = a->data[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = last;
	}
	if (print && !(stats && stats->suppress_print))
		ft_putstr_fd("rra\n", 1);
	if (stats)
		stats->rra++;
}

void	op_rrb(t_stack *b, int print, t_stats *stats)
{
	int	last;
	int	i;

	if (b->size >= 2)
	{
		last = b->data[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = last;
	}
	if (print && !(stats && stats->suppress_print))
		ft_putstr_fd("rrb\n", 1);
	if (stats)
		stats->rrb++;
}

void	op_rrr(t_stack *a, t_stack *b, int print, t_stats *stats)
{
	op_rra(a, 0, NULL);
	op_rrb(b, 0, NULL);
	if (print && !(stats && stats->suppress_print))
		ft_putstr_fd("rrr\n", 1);
	if (stats)
		stats->rrr++;
}
