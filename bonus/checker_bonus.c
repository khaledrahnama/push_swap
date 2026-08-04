/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:35:17 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/04 14:50:08 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	ft_memcpy_local(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static char	*read_stdin(void)
{
	char	buf[1024];
	char	*result;
	char	*tmp;
	int		bytes;
	int		res_len;

	result = malloc(1);
	result[0] = '\0';
	res_len = 0;
	bytes = read(0, buf, 1024);
	while (bytes > 0)
	{
		tmp = malloc(res_len + bytes + 1);
		if (!tmp)
			error_exit();
		ft_memcpy_local(tmp, result, res_len);
		ft_memcpy_local(tmp + res_len, buf, bytes);
		tmp[res_len + bytes] = '\0';
		free(result);
		result = tmp;
		res_len += bytes;
		bytes = read(0, buf, 1024);
	}
	return (result);
}

static void	execute_line(char *line, t_stack *a, t_stack *b)
{
	if (ft_strequ(line, "sa"))
		op_sa(a, 0, NULL);
	else if (ft_strequ(line, "sb"))
		op_sb(b, 0, NULL);
	else if (ft_strequ(line, "ss"))
		op_ss(a, b, 0, NULL);
	else if (ft_strequ(line, "pa"))
		op_pa(a, b, 0, NULL);
	else if (ft_strequ(line, "pb"))
		op_pb(a, b, 0, NULL);
	else if (ft_strequ(line, "ra"))
		op_ra(a, 0, NULL);
	else if (ft_strequ(line, "rb"))
		op_rb(b, 0, NULL);
	else if (ft_strequ(line, "rr"))
		op_rr(a, b, 0, NULL);
	else if (ft_strequ(line, "rra"))
		op_rra(a, 0, NULL);
	else if (ft_strequ(line, "rrb"))
		op_rrb(b, 0, NULL);
	else if (ft_strequ(line, "rrr"))
		op_rrr(a, b, 0, NULL);
	else if (line[0] != '\0')
		error_exit();
}

static void	process_all_lines(char *input, t_stack *a, t_stack *b)
{
	int		i;
	int		start;
	char	saved;

	i = 0;
	start = 0;
	while (1)
	{
		if (input[i] == '\n' || input[i] == '\0')
		{
			saved = input[i];
			input[i] = '\0';
			execute_line(input + start, a, b);
			input[i] = saved;
			start = i + 1;
			if (saved == '\0')
				break ;
		}
		i++;
	}
}

static int	is_sorted(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->size)
	{
		if (a->data[i] < a->data[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*input;

	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	stack_init(&b, a.size + 1);
	input = read_stdin();
	process_all_lines(input, &a, &b);
	free(input);
	if (is_sorted(&a) && b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	stack_free(&a);
	stack_free(&b);
	return (0);
}