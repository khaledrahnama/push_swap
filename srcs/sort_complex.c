/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/21 11:54:14 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sweep_by_bit(t_stack *a, t_stack *b, t_radix_ctx *ctx, int bit)
{
	int	count;
	int	i;
	int	rank;

	count = a->size;
	i = 0;
	while (i < count)
	{
		rank = rank_of(a->data[0], ctx->sorted, ctx->n);
		if (((rank >> bit) & 1) == 0)
			op_pb(a, b, 1, ctx->stats);
		else
			op_ra(a, 1, ctx->stats);
		i++;
	}
	while (b->size > 0)
		op_pa(a, b, 1, ctx->stats);
}

void	sort_complex(t_stack *a, t_stack *b, t_stats *stats)
{
	t_radix_ctx	ctx;
	int			nbits;
	int			bit;

	if (a->size < 2)
		return ;
	ctx.n = a->size;
	ctx.sorted = build_sorted_copy(a);
	ctx.stats = stats;
	nbits = nbits_for(ctx.n);
	bit = 0;
	while (bit < nbits)
	{
		sweep_by_bit(a, b, &ctx, bit);
		bit++;
	}
	free(ctx.sorted);
}
