/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:45:28 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/06 13:30:50 by semirkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_ops(t_stats *stats)
{
	return (stats->sa + stats->sb + stats->ss + stats->pa + stats->pb
		+ stats->ra + stats->rb + stats->rr + stats->rra + stats->rrb
		+ stats->rrr);
}

void	print_bench(t_stats *stats, int disorder_val, const char *strat,
		const char *complexity)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder_pct(disorder_val, 2);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strat, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(stats), 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(stats->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(stats->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(stats->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(stats->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
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
