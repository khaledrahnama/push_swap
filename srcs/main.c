/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:41:31 by semirkar          #+#    #+#             */
/*   Updated: 2026/08/25 21:42:24 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*complexity_for(int method)
{
	if (method == METHOD_SIMPLE)
		return ("O(n^2)");
	if (method == METHOD_MEDIUM)
		return ("O(n*sqrt(n))");
	if (method == METHOD_COMPLEX)
		return ("O(n log n)");
	if (method == METHOD_SMALL)
		return ("O(1)");
	return ("n/a");
}

static const char	*name_for(int method, int adaptive)
{
	if (!adaptive)
	{
		if (method == METHOD_SIMPLE)
			return ("Simple");
		if (method == METHOD_MEDIUM)
			return ("Medium");
		return ("Complex");
	}
	if (method == METHOD_SIMPLE)
		return ("Adaptive (Simple)");
	if (method == METHOD_MEDIUM)
		return ("Adaptive (Medium)");
	if (method == METHOD_COMPLEX)
		return ("Adaptive (Complex)");
	if (method == METHOD_SMALL)
		return ("Adaptive (Small)");
	return ("Adaptive");
}

static int	forced_method(t_flags *flags)
{
	if (flags->simple)
		return (METHOD_SIMPLE);
	if (flags->medium)
		return (METHOD_MEDIUM);
	if (flags->complex)
		return (METHOD_COMPLEX);
	
	return (METHOD_NONE);
}

static int	run_sort(t_flags *flags, t_run_ctx *ctx)
{
	int	method;

	method = forced_method(flags);
	if(!stack_is_sorted(ctx->a))
	{
		if (method == METHOD_SIMPLE)
			sort_simple(ctx->a, ctx->b, ctx->stats);
		else if (method == METHOD_MEDIUM)
			sort_medium(ctx->a, ctx->b, ctx->stats);
		else if (method == METHOD_COMPLEX)
			sort_complex(ctx->a, ctx->b, ctx->stats);
		else
			method = sort_adaptive(ctx->a, ctx->b, ctx->stats);
	}
	if (flags->count_only)
	{
		ft_putnbr_fd(total_ops(ctx->stats),1);
		ft_putstr_fd("\n",1);
	}
	return (method);
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
	flags = (t_flags){0, 0, 0, 0, 0, 0};
	init_and_parse(argc, argv, &flags, &a);
	stack_init(&b, a.size);
	stats = (t_stats){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, flags.count_only};
	ctx = (t_run_ctx){&a, &b, &stats, disorder_of(&a), forced_method(&flags)};
		ctx.method = run_sort(&flags, &ctx);
	if (flags.bench)
		print_bench(&stats, ctx.disorder,
			name_for(ctx.method, forced_method(&flags) == METHOD_NONE),
			complexity_for(ctx.method));
	
	stack_free(&a);
	stack_free(&b);
	return (0);
}
