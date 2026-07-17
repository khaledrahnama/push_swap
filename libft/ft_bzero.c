/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:08:00 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/29 10:29:12 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
		bzero, explicit_bzero - zero a byte string

SYNOPSIS
		#include <strings.h>

		void bzero(void *s, size_t n);

		#include <string.h>

		void explicit_bzero(void *s, size_t n);

DESCRIPTION
		The bzero() function erases the data in the n bytes of the memory
		starting at the location pointed to by s,
		by writing zeros (bytes containing '\0') to that area.

		The  explicit_bzero()  function  performs the same task as bzero().
		It differs from bzero() in that it
		guarantees that compiler optimizations will not remove
				the erase operation if the compiler de‐
		duces that the operation is "unnecessary".

RETURN VALUE
		None.
		*/

/* #include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
 */

#include "libft.h"
/*
 void ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
} */
/* void ft_bzero(void *s, size_t n)
{
	ptr = (unsigned char*) s ;
	ft_memset(ptr, 0 , n);
}
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello";

	printf("Before: %s\n", str);

	ft_bzero(str, 3);

	printf("After bytes:\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", str[i]);
	}

	printf("\n");

	return (0);
} */