/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:10:41 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 19:09:10 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/*

 char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s);
	while ( i <= length)
	{
		if ((unsigned char) s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
		return (NULL);
}


#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*ptr;

	str = "something";
	printf("%s \n", ft_strchr(str, 't'));
	printf("%s \n", ft_strchr(str, 'x'));
	printf("%s \n", strchr(str, '\0'));
	printf("%s \n", ft_strchr(str, 'g'));
	ptr = ft_strchr(str, '\0');
	printf("address of end : %p \n", ptr);
	printf("character there: %d\n", *ptr);
	printf("Length using pointer math: %ld\n", ptr - str);
	if (*ptr == '\0')
		printf("found null terminator\n");
	printf("%s \n", strchr(str, 't'));
	printf("%s \n", strchr(str, 'x'));
	printf("%s \n", strchr(str, '\0'));
	printf("%s \n", strchr(str, 'g'));
	printf("address of end : %p \n", ptr);
	printf("character there: %d\n", *ptr);
	printf("Length using pointer math: %ld\n", ptr - str);
	if (*ptr == '\0')
		printf("found null terminator\n");
}


#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char str[] = "hello";

	char *ptr1 = ft_strchr(str, 'e');
	char *ptr2 = ft_strchr(str, 'z');
	char *ptr3 = ft_strchr(str, '\0');

	if (ptr1)
		printf("Found 'e': %s\n", ptr1);
	else
		printf("'e' not found\n");

	if (ptr2)
		printf("Found 'z': %s\n", ptr2);
	else
		printf("'z' not found\n");

	if (ptr3)
		printf("Found '\\0' at index: %ld\n", ptr3 - str);

	return (0);
} */