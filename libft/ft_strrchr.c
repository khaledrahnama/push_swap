/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:10:55 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 00:31:16 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

/*
char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s)
	{
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	while (s >= start)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

 */

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s \n", ft_strrchr("something", 't'));
}
 */

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "sgomethitngooo";
	char *ptr;
	printf("%s \n" , ft_strrchr("a",'a'));
	printf("%s \n", ft_strrchr(str, 's'));
	printf("%s \n", ft_strrchr(str, 't'));
	printf("%s \n", ft_strrchr(str, 'x'));
	printf("%s \n", strrchr(str, '\0'));
	printf("%s \n", ft_strrchr(str, 'g'));

	ptr = ft_strrchr(str, '\0');

	printf("address of end : %p \n", ptr);
	printf("character there: %d\n", *ptr);
	printf("Length using pointer math: %ld\n", ptr - str);

	if (*ptr == '\0')
		printf("found null terminator\n");

	printf("%s \n" ,strrchr("a",'a'));
	printf("%s \n", strrchr(str, 's'));
	printf("%s \n", strrchr(str, 't'));
	printf("%s \n", strrchr(str, 'x'));
	printf("%s \n", strrchr(str, '\0'));
	printf("%s \n", strrchr(str, 'g'));

	printf("address of end : %p \n", ptr);
	printf("character there: %d\n", *ptr);
	printf("Length using pointer math: %ld\n", ptr - str);
	if (*ptr == '\0')
		printf("found null terminator\n");
}  */