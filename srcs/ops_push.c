/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:13:43 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/06 23:50:03 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b, int print, t_stats *stats)
{
	int	i;

	if (b->size > 0)
	{
		i = a->size;
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = b->data[0];
		a->size++;
		i = 0;
		while (i < b->size - 1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->size--;
	}
	if (print)
		ft_putstr_fd("pa\n", 1);
	if (stats)
		stats->pa++;
}

void	op_pb(t_stack *a, t_stack *b, int print, t_stats *stats)
{
	int	i;

	if (a->size > 0)
	{
		i = b->size;
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = a->data[0];
		b->size++;
		i = 0;
		while (i < a->size - 1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->size--;
	}
	if (print)
		ft_putstr_fd("pb\n", 1);
	if (stats)
		stats->pb++;
}