/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:06:24 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 17:33:08 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void)
{
	int		*data;
	t_list	*node1;
	t_list	*node2;

	data = malloc(sizeof(int));
	*data = 42;
	node1 = ft_lstnew(data);
	if(node1)
	{
		printf("Node created successfully! \n ");
		printf("Node address: %p \n", node1);
		printf("Node content address: %p \n", node1-> content);
		printf("Node content value:%d\n",*(int *)(node1->content));
		printf("Node next pointer:%p (should be NULL)\n", node1->next);
	}
   // test with string
   node2 = ft_lstnew("Hello World");
   if(node2)
   {
	printf("\n Node2 created successfully");
	printf("Node2 content: %s \n", (char *) node2-> content);
	printf("Node2 next: %p (should be NULL) \n", node2->next);
   }
}
   */