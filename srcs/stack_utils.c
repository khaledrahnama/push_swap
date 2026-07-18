/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:51:52 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/18 11:59:34 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, int capacity)
{
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		write(2, "Error\n", 6);
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

	i = 0;
	printf("Stack %c (size %d): ", name, stack->size);
	while (i < stack->size)
	{
		printf("%d ", stack->data[i]);
		i++;
	}
	printf("\n");
}