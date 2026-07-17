/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:47:54 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 01:19:45 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	del(void *ptr)
{
	free(ptr);
}

void	*add_title(void *content)
{
	char	*name;

	name = (char *)content;
	char *result = malloc(ft_strlen(name) + 5); // "Sir " + '\0'
	if (!result)
		return (NULL);
	sprintf(result, "Sir %s", name);
	return (result);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	t_list *original;
	t_list *mapped;

	node1 = ft_lstnew(ft_strdup("Arthur"));
	node2 = ft_lstnew(ft_strdup("Merlin"));
	node3 = ft_lstnew(ft_strdup("Lancelot"));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	original = node1;

	printf("Original list:\n");
	print_list(original);

	mapped = ft_lstmap(original, add_title, del);

	printf("\n Mapped list:\n");
	print_list(mapped);

	ft_lstclear(&original, del);
	ft_lstclear(&mapped, del);

	return (0);
} */