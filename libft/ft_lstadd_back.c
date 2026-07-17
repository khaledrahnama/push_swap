/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:11:14 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 17:33:46 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
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

	ft_lstadd_back(&head, node1);
	print_list(head);

	ft_lstadd_back(&head, node2);
	print_list(head);

	ft_lstadd_back(&head, node3);
	print_list(head);

	return (0);
} */