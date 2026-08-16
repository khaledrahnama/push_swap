/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a, int print, t_stats *stats)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = tmp;
	}
	if (print && !(stats && stats->suppress_print))
		ft_putstr_fd("sa\n", 1);
	if (stats)
		stats->sa++;
}

void	op_sb(t_stack *b, int print, t_stats *stats)
{
	int	tmp;

	if (b->size >= 2)
	{
		tmp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = tmp;
	}
	if (print && !(stats && stats->suppress_print))
		ft_putstr_fd("sb\n", 1);
	if (stats)
		stats->sb++;
}

void	op_ss(t_stack *a, t_stack *b, int print, t_stats *stats)
{
	op_sa(a, 0, NULL);
	op_sb(b, 0, NULL);
	if (print && !(stats && stats->suppress_print))
		ft_putstr_fd("ss\n", 1);
	if (stats)
		stats->ss++;
}
