/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:54:11 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/18 12:01:47 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	(void)argv;
	(void)argc;
	stack_init(&a, 5);
	stack_init(&b, 5);

	a.data[0] = 3;
	a.data[1] = 1;
	a.data[2] = 2;
	a.size = 3;

	stack_print(&a, 'a');
	stack_print(&b, 'b');

	stack_free(&a);
	stack_free(&b);
	return (0);
}