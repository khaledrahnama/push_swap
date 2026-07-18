/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:49:15 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/07/18 11:50:51 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

int		main(int argc, char **argv);
void	stack_init(t_stack *stack, int capacity);
void	stack_free(t_stack *stack);
void	stack_print(t_stack *stack, char name);

#endif