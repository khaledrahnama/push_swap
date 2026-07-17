/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:07:57 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 17:33:20 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void	del(void *ptr)
{
	free(ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void *)); // your function

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*lst;
	t_list	*current;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node1->content = strdup("hello");
	node2->content = strdup("world");
	node3->content = strdup("libft");
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	lst = node1;
	current = lst;
while (current)
{
	printf("Before clear: %s --> \n", (char *)current->content);
	current = current->next;
}

	ft_lstclear(&lst, del);

	if (lst == NULL)
		printf("List cleared successfully\n");

	return (0);
}*/