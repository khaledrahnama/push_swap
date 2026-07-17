/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:11:11 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 19:01:44 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*start;

	start = (const unsigned char *)s;
	while (n--)
	{
		if (*start == (unsigned char)c)
			return ((void *)start);
		start++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[]="abcdefghi";

	char *ptr;
	ptr = ft_memchr(str, 'd' , 6);

	printf("pointer is %p \n",ptr);
	printf("value is %c \n",*ptr);
	printf("value is %s \n",ptr);

	return (0);
} */