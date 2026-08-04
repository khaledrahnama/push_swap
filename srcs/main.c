/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:54:11 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/04 14:46:56 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	bench;
}	t_flags;

static char	**filter_flags(int argc, char **argv, int *out_argc,
		t_flags *flags)
{
	char	**filtered;
	int		fcount;
	int		i;

	filtered = malloc(sizeof(char *) * (argc + 1));
	if (!filtered)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	fcount = 0;
	filtered[fcount++] = argv[0];
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "--simple"))
			flags->simple = 1;
		else if (ft_strequ(argv[i], "--medium"))
			flags->medium = 1;
		else if (ft_strequ(argv[i], "--complex"))
			flags->complex = 1;
		else if (ft_strequ(argv[i], "--adaptive"))
			;
		else if (ft_strequ(argv[i], "--bench"))
			flags->bench = 1;
		else
			filtered[fcount++] = argv[i];
		i++;
	}
	*out_argc = fcount;
	return (filtered);
}

static void	run_strategy(t_flags *flags, t_stack *a, t_stack *b,
		t_stats *stats, const char **name, const char **complexity)
{
	int	regime;

	if (flags->simple)
	{
		sort_simple(a, b, stats);
		*name = "Simple";
		*complexity = "O(n^2)";
	}
	else if (flags->medium)
	{
		sort_medium(a, b, stats);
		*name = "Medium";
		*complexity = "O(n*sqrt(n))";
	}
	else if (flags->complex)
	{
		sort_complex(a, b, stats);
		*name = "Complex";
		*complexity = "O(n log n)";
	}
	else
	{
		regime = sort_adaptive(a, b, stats);
		*name = "Adaptive";
		if (regime == 0)
			*complexity = "O(n^2)";
		else if (regime == 1)
			*complexity = "O(n*sqrt(n))";
		else
			*complexity = "O(n log n)";
	}
}

int	main(int argc, char **argv)
{
	t_flags		flags;
	char		**filtered;
	int			filtered_argc;
	t_stack		a;
	t_stack		b;
	t_stats		stats;
	int			disorder_val;
	const char	*strat_name;
	const char	*strat_complexity;

	flags = (t_flags){0, 0, 0, 0};
	stats = (t_stats){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (argc < 2)
		return (0);
	filtered = filter_flags(argc, argv, &filtered_argc, &flags);
	if (filtered_argc < 2)
	{
		free(filtered);
		return (0);
	}
	parse_args(filtered_argc, filtered, &a);
	free(filtered);
	stack_init(&b, a.size);
	disorder_val = disorder_scaled(&a);
	run_strategy(&flags, &a, &b, &stats, &strat_name, &strat_complexity);
	if (flags.bench)
		print_bench(&stats, disorder_val, strat_name, strat_complexity);
	stack_free(&a);
	stack_free(&b);
	return (0);
}