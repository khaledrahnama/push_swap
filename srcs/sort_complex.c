/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:32:56 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/28 13:33:25 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	n;
	int	nbits;
	int	bit;
	int	count;
	int	i;
	int	rank;

	if (a->size < 2)
		return ;
	n = a->size;
	sorted = build_sorted_copy(a);
	nbits = nbits_for(n);
	bit = 0;
	while (bit < nbits)
	{
		count = a->size;
		i = 0;
		while (i < count)
		{
			rank = rank_of(a->data[0], sorted, n);
			if (((rank >> bit) & 1) == 0)
				op_pb(a, b, 1);
			else
				op_ra(a, 1);
			i++;
		}
		while (b->size > 0)
			op_pa(a, b, 1);
		bit++;
	}
	free(sorted);
}