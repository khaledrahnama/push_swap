/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semirkar <semirkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:43:37 by semirkar          #+#    #+#             */
/*   Updated: 2026/08/25 21:43:39 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(t_stats *stats)
{
	return (stats->sa + stats->sb + stats->ss + stats->pa + stats->pb
		+ stats->ra + stats->rb + stats->rr
		+ stats->rra + stats->rrb + stats->rrr);
}

static void	print_bench_header(double disorder, const char *strat,
		const char *complexity)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder_pct(disorder, 2);
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

void	print_bench(t_stats *stats, double disorder, const char *strat,
		const char *complexity)
{
	print_bench_header(disorder, strat, complexity);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(stats), 2);
	ft_putstr_fd("\n", 2);
	print_bench_counts1(stats);
	print_bench_counts2(stats);
}
