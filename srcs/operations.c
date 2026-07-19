/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:25:22 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/19 15:25:27 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a, int print)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = tmp;
	}
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_stack *b, int print)
{
	int	tmp;

	if (b->size >= 2)
	{
		tmp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = tmp;
	}
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_stack *a, t_stack *b, int print)
{
	op_sa(a, 0);
	op_sb(b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	op_pa(t_stack *a, t_stack *b, int print)
{
	int	i;

	if (b->size > 0)
	{
		i = a->size;
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = b->data[0];
		a->size++;
		i = 0;
		while (i < b->size - 1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->size--;
	}
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_stack *a, t_stack *b, int print)
{
	int	i;

	if (a->size > 0)
	{
		i = b->size;
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = a->data[0];
		b->size++;
		i = 0;
		while (i < a->size - 1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->size--;
	}
	if (print)
		ft_putstr_fd("pb\n", 1);
}

void	op_ra(t_stack *a, int print)
{
	int	first;
	int	i;

	if (a->size >= 2)
	{
		first = a->data[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[a->size - 1] = first;
	}
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_stack *b, int print)
{
	int	first;
	int	i;

	if (b->size >= 2)
	{
		first = b->data[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[b->size - 1] = first;
	}
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	op_rr(t_stack *a, t_stack *b, int print)
{
	op_ra(a, 0);
	op_rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

void	op_rra(t_stack *a, int print)
{
	int	last;
	int	i;

	if (a->size >= 2)
	{
		last = a->data[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = last;
	}
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_stack *b, int print)
{
	int	last;
	int	i;

	if (b->size >= 2)
	{
		last = b->data[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = last;
	}
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	op_rrr(t_stack *a, t_stack *b, int print)
{
	op_rra(a, 0);
	op_rrb(b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}