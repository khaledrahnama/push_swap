/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:54:11 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/06 23:50:08 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*complexity_for_regime(int regime)
{
	if (regime == 0)
		return ("O(n^2)");
	else if (regime == 1)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

static void	run_forced(t_flags *flags, t_run_ctx *ctx)
{
	if (flags->simple)
	{
		sort_simple(ctx->a, ctx->b, ctx->stats);
		ctx->name = "Simple";
		ctx->complexity = "O(n^2)";
	}
	else if (flags->medium)
	{
		sort_medium(ctx->a, ctx->b, ctx->stats);
		ctx->name = "Medium";
		ctx->complexity = "O(n*sqrt(n))";
	}
	else
	{
		sort_complex(ctx->a, ctx->b, ctx->stats);
		ctx->name = "Complex";
		ctx->complexity = "O(n log n)";
	}
}

static void	run_strategy(t_flags *flags, t_run_ctx *ctx)
{
	int	regime;

	if (flags->simple || flags->medium || flags->complex)
		run_forced(flags, ctx);
	else
	{
		regime = sort_adaptive(ctx->a, ctx->b, ctx->stats);
		ctx->name = "Adaptive";
		ctx->complexity = complexity_for_regime(regime);
	}
}

int	main(int argc, char **argv)
{
	t_flags		flags;
	t_stack		a;
	t_stack		b;
	t_stats		stats;
	t_run_ctx	ctx;

	if (argc < 2)
		return (0);
	flags = (t_flags){0, 0, 0, 0};
	init_and_parse(argc, argv, &flags, &a);
	stack_init(&b, a.size);
	stats = (t_stats){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	ctx = (t_run_ctx){&a, &b, &stats, disorder_scaled(&a), "", ""};
	run_strategy(&flags, &ctx);
	if (flags.bench)
		print_bench(ctx.stats, ctx.disorder, ctx.name, ctx.complexity);
	stack_free(&a);
	stack_free(&b);
	return (0);
}