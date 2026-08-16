/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *a, int print, t_stats *stats)
{
	int	first;
	int	i;

	if (a->size >= 2)
	{
		first = a->data[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[a->size - 1] = first;
	}
	if (print)
		ft_putstr_fd("ra\n", 1);
	if (stats)
		stats->ra++;
}

void	op_rb(t_stack *b, int print, t_stats *stats)
{
	int	first;
	int	i;

	if (b->size >= 2)
	{
		first = b->data[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[b->size - 1] = first;
	}
	if (print)
		ft_putstr_fd("rb\n", 1);
	if (stats)
		stats->rb++;
}

void	op_rr(t_stack *a, t_stack *b, int print, t_stats *stats)
{
	op_ra(a, 0, NULL);
	op_rb(b, 0, NULL);
	if (print)
		ft_putstr_fd("rr\n", 1);
	if (stats)
		stats->rr++;
}
