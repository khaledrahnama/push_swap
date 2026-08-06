/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:51:52 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/07 00:02:21 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, int capacity)
{
	if (capacity <= 0)
	{
		stack->data = NULL;
		stack->size = 0;
		return ;
	}
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stack->size = 0;
}

void	stack_free(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}

void	stack_print(t_stack *stack, char name)
{
	int	i;

	ft_putstr_fd("Stack ", 1);
	write(1, &name, 1);
	ft_putstr_fd(": ", 1);
	i = 0;
	while (i < stack->size)
	{
		ft_putnbr_fd((long)stack->data[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}
