/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:17:55 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/07 00:01:38 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	match_flag(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "--simple"))
		flags->simple = 1;
	else if (ft_strequ(arg, "--medium"))
		flags->medium = 1;
	else if (ft_strequ(arg, "--complex"))
		flags->complex = 1;
	else if (ft_strequ(arg, "--adaptive"))
		return (1);
	else if (ft_strequ(arg, "--bench"))
		flags->bench = 1;
	else
		return (0);
	return (1);
}

static char	**filter_flags(int argc, char **argv, int *out_argc,
		t_flags *flags)
{
	char	**filtered;
	int		fcount;
	int		i;

	filtered = malloc(sizeof(char *) * (argc + 1));
	if (!filtered)
		error_exit();
	fcount = 0;
	filtered[fcount++] = argv[0];
	i = 1;
	while (i < argc)
	{
		if (!match_flag(argv[i], flags))
			filtered[fcount++] = argv[i];
		i++;
	}
	*out_argc = fcount;
	return (filtered);
}

void	init_and_parse(int argc, char **argv, t_flags *flags, t_stack *a)
{
	char	**filtered;
	int		filtered_argc;

	filtered = filter_flags(argc, argv, &filtered_argc, flags);
	if (filtered_argc < 2)
	{
		free(filtered);
		exit(0);
	}
	parse_args(filtered_argc, filtered, a);
	free(filtered);
}
