/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:00:00 by khaledrahnama     #+#    #+#             */
/*   Updated: 2026/08/16 00:00:00 by khaledrahnama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_stats;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	bench;
}	t_flags;

typedef struct s_run_ctx
{
	t_stack		*a;
	t_stack		*b;
	t_stats		*stats;
	int			disorder;
	const char	*name;
	const char	*complexity;
}	t_run_ctx;

typedef struct s_chunk
{
	int	min;
	int	max;
}	t_chunk;

typedef struct s_chunk_plan
{
	int	*sorted;
	int	n;
	int	chunk_size;
	int	num_chunks;
}	t_chunk_plan;

typedef struct s_radix_ctx
{
	int		*sorted;
	int		n;
	t_stats	*stats;
}	t_radix_ctx;

int		main(int argc, char **argv);

void	stack_init(t_stack *stack, int capacity);
void	stack_free(t_stack *stack);
void	stack_print(t_stack *stack, char name);

void	error_exit(void);
char	*join_args(int argc, char **argv);
long	parse_number(char *str, int *idx);
int		already_seen(t_stack *a, int value);
void	parse_args(int argc, char **argv, t_stack *a);
void	init_and_parse(int argc, char **argv, t_flags *flags, t_stack *a);

int		ft_isdigit(char c);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(const char *s, int fd);
int		ft_strequ(const char *a, const char *b);

void	op_sa(t_stack *a, int print, t_stats *stats);
void	op_sb(t_stack *b, int print, t_stats *stats);
void	op_ss(t_stack *a, t_stack *b, int print, t_stats *stats);
void	op_pa(t_stack *a, t_stack *b, int print, t_stats *stats);
void	op_pb(t_stack *a, t_stack *b, int print, t_stats *stats);
void	op_ra(t_stack *a, int print, t_stats *stats);
void	op_rb(t_stack *b, int print, t_stats *stats);
void	op_rr(t_stack *a, t_stack *b, int print, t_stats *stats);
void	op_rra(t_stack *a, int print, t_stats *stats);
void	op_rrb(t_stack *b, int print, t_stats *stats);
void	op_rrr(t_stack *a, t_stack *b, int print, t_stats *stats);

void	sort_simple(t_stack *a, t_stack *b, t_stats *stats);
void	sort_medium(t_stack *a, t_stack *b, t_stats *stats);
void	sort_complex(t_stack *a, t_stack *b, t_stats *stats);
int		sort_adaptive(t_stack *a, t_stack *b, t_stats *stats);

int		int_sqrt(int n);
void	copy_ints(int *dst, int *src, int n);
void	sort_ints_med(int *arr, int n);
void	build_chunk_plan(t_stack *a, t_chunk_plan *plan);
void	get_chunk_bounds(t_chunk_plan *plan, int c, t_chunk *chunk);

int		*build_sorted_copy(t_stack *a);
int		rank_of(int value, int *sorted, int n);
int		nbits_for(int n);

int		count_mistakes(t_stack *a);
int		total_pairs(int n);
int		disorder_scaled(t_stack *a);
void	print_disorder_pct(int scaled, int fd);

void	print_bench(t_stats *stats, int disorder_val, const char *strat,
			const char *complexity);

#endif
