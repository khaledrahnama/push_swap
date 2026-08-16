/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:40:37 by semirkar          #+#    #+#             */
/*   Updated: 2026/08/16 15:40:45 by semirkar         ###   ########.fr       */
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
	flags = (t_flags){0, 0, 0, 0, 0};
	init_and_parse(argc, argv, &flags, &a);
	stack_init(&b, a.size);
<<<<<<< HEAD
	stats = (t_stats){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	ctx = (t_run_ctx){&a, &b, &stats, disorder_scaled(&a), "", ""};
	if (ctx.disorder == 0)
	{
		if (flags.bench == 1)
			print_bench(&ctx);
		stack_free(&a);
		stack_free(&b);		
		return (0);
	}
	
	run_strategy(&flags, &ctx);
=======
	stats = (t_stats){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, flags.count_only};
	ctx = (t_run_ctx){&a, &b, &stats, disorder_scaled(&a), "None", "O(1)"};
	if (ctx.disorder != 0)
		run_strategy(&flags, &ctx);
	if (flags.count_only)
	{
		ft_putnbr_fd(count_total_ops(ctx.stats), 1);
		ft_putstr_fd("\n", 1);
	}
>>>>>>> cc4c66d7702098591422b1152bf4247be857ef0c
	if (flags.bench)
		print_bench(&ctx);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
