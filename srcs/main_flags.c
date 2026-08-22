/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
=======
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/22 12:32:14 by krahnama         ###   ########.fr       */
>>>>>>> 45c633a4575637f329568428fa8638f9d3aa86e0
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
static void	set_flag_once(int *field)
{
	if (*field)
=======
static void set_flags_once(int *field)
{
	if(*field)
>>>>>>> 45c633a4575637f329568428fa8638f9d3aa86e0
		error_exit();
	*field = 1;
}

static int	match_flag(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "--simple"))
<<<<<<< HEAD
		set_flag_once(&flags->simple);
	else if (ft_strequ(arg, "--medium"))
		set_flag_once(&flags->medium);
	else if (ft_strequ(arg, "--complex"))
		set_flag_once(&flags->complex);
	else if (ft_strequ(arg, "--adaptive"))
		set_flag_once(&flags->adaptive);
	else if (ft_strequ(arg, "--bench"))
		set_flag_once(&flags->bench);
=======
		set_flags_once(&flags->simple);
	else if (ft_strequ(arg, "--medium"))
		set_flags_once(&flags->medium);
	else if (ft_strequ(arg, "--complex"))
		set_flags_once(&flags->complex);
	else if (ft_strequ(arg, "--adaptive"))
		set_flags_once(&flags->adaptive);
	else if (ft_strequ(arg, "--bench"))
		set_flags_once(&flags->bench);
>>>>>>> 45c633a4575637f329568428fa8638f9d3aa86e0
	else
		return (0);
	return (1);
}

<<<<<<< HEAD
static int	count_leading_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	while (i < argc && match_flag(argv[i], flags))
		i++;
	return (i);
}
=======

>>>>>>> 45c633a4575637f329568428fa8638f9d3aa86e0

static char	**filter_flags(int argc, char **argv, int *out_argc,
		t_flags *flags)
{
	char	**filtered;
	int		start;
	int		fcount;
	int		i;

	start = count_leading_flags(argc, argv, flags);
	filtered = malloc(sizeof(char *) * (argc + 1));
	if (!filtered)
		error_exit();
	filtered[0] = argv[0];
	fcount = 1;
	i = start;
	while (i < argc)
	{
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
	int		count;

	filtered = filter_flags(argc, argv, &filtered_argc, flags);
	count = flags->simple + flags->medium + flags->complex + flags->adaptive;
	if (count > 1)
	{
		free(filtered);
		error_exit();
	}
	if (filtered_argc < 2)
	{
		free(filtered);
		exit(0);
	}
	if (!parse_args(filtered_argc, filtered, a))
	{
		free(filtered);
		exit(1);
	}
	free(filtered);
}
