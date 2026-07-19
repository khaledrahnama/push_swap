/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:54:11 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/19 15:35:06 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	a;
	t_stack	b;
	int		vals[6] = {2, 1, 3, 6, 5, 8};
	int		i;

	stack_init(&a, 6);
	stack_init(&b, 6);
	i = 0;
	while (i < 6)
	{
		a.data[i] = vals[i];
		i++;
	}
	a.size = 6;

	op_sa(&a, 1);
	stack_print(&a, 'a');

	op_pb(&a, &b, 1);
	op_pb(&a, &b, 1);
	op_pb(&a, &b, 1);
	stack_print(&a, 'a');
	stack_print(&b, 'b');

	op_rr(&a, &b, 1);
	stack_print(&a, 'a');
	stack_print(&b, 'b');

	op_rrr(&a, &b, 1);
	stack_print(&a, 'a');
	stack_print(&b, 'b');

	op_sa(&a, 1);
	stack_print(&a, 'a');

	op_pa(&a, &b, 1);
	op_pa(&a, &b, 1);
	op_pa(&a, &b, 1);
	stack_print(&a, 'a');
	stack_print(&b, 'b');

	stack_free(&a);
	stack_free(&b);
	return (0);
}
