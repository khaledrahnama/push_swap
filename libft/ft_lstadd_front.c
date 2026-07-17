/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:08:22 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 17:33:23 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include "libft.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}


int	main(void)
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	head = NULL;

	node1 = ft_lstnew("hello");
	node2 = ft_lstnew("world");
	node3 = ft_lstnew("libft");

	printf("Initial list:\n");
	print_list(head);

	ft_lstadd_front(&head, node1);
	printf("\nAfter adding node1:\n");
	print_list(head);

	ft_lstadd_front(&head, node2);
	printf("\nAfter adding node2:\n");
	print_list(head);

	ft_lstadd_front(&head, node3);
	printf("\nAfter adding node3:\n");
	print_list(head);

	return (0);
} */