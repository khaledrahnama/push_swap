/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_ops(t_stats *stats)
{
	return (stats->sa + stats->sb + stats->ss + stats->pa + stats->pb
		+ stats->ra + stats->rb + stats->rr
		+ stats->rra + stats->rrb + stats->rrr);
}

static void	print_bench_header(int disorder_val, const char *strat,
		const char *complexity)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder_pct(disorder_val, 2);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strat, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_bench_counts1(t_stats *stats)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(stats->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(stats->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(stats->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(stats->pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_bench_counts2(t_stats *stats)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(stats->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(stats->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(stats->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(stats->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(stats->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(stats->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_run_ctx *ctx)
{
	print_bench_header(ctx->disorder, ctx->name, ctx->complexity);
	ft_putstr_fd("[bench] total_ops: ", 2);
<<<<<<< HEAD
	ft_putnbr_fd(total_ops(ctx->stats), 2);
=======
	ft_putnbr_fd(count_total_ops(stats), 2);
>>>>>>> cc4c66d7702098591422b1152bf4247be857ef0c
	ft_putstr_fd("\n", 2);
	print_bench_counts1(ctx->stats);
	print_bench_counts2(ctx->stats);
}
