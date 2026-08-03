#include "push_swap.h"

static void	sweep_chunk(t_stack *a, t_stack *b, int cmin, int cmax)
{
	int	sweep_count;
	int	i;

	sweep_count = a->size;
	i = 0;
	while (i < sweep_count)
	{
		if (a->data[0] >= cmin && a->data[0] <= cmax)
			op_pb(a, b, 1);
		else
			op_ra(a, 1);
		i++;
	}
}

static int	find_max_index(t_stack *b)
{
	int	max_idx;
	int	i;

	max_idx = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->data[i] > b->data[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

static void	rotate_b_to_top(t_stack *b, int index)
{
	int	steps_up;
	int	steps_down;

	steps_up = index;
	steps_down = b->size - index;
	if (steps_up <= steps_down)
	{
		while (steps_up-- > 0)
			op_rb(b, 1);
	}
	else
	{
		while (steps_down-- > 0)
			op_rrb(b, 1);
	}
}

static void	drain_max_to_a(t_stack *a, t_stack *b)
{
	int	max_idx;

	while (b->size > 0)
	{
		max_idx = find_max_index(b);
		rotate_b_to_top(b, max_idx);
		op_pa(a, b, 1);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	n;
	int	*sorted;
	int	chunk_size;
	int	num_chunks;
	int	c;
	int	hi_i;

	n = a->size;
	if (n < 2)
		return ;
	sorted = malloc(sizeof(int) * n);
	if (!sorted)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	copy_ints(sorted, a->data, n);
	sort_ints_med(sorted, n);
	chunk_size = (int_sqrt(n) * 5) / 2;
	if (chunk_size < 1)
		chunk_size = 1;
	num_chunks = (n + chunk_size - 1) / chunk_size;
	c = num_chunks - 1;
	while (c >= 0)
	{
		hi_i = (c + 1) * chunk_size - 1;
		if (hi_i > n - 1)
			hi_i = n - 1;
		sweep_chunk(a, b, sorted[c * chunk_size], sorted[hi_i]);
		drain_max_to_a(a, b);
		c--;
	}
	free(sorted);
}
