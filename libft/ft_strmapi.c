/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:00:19 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 02:04:52 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!s || !f)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* #include <stdio.h>
#include <stdlib.h>

char	change(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

int	main(void)
{
	char	*str;
	// Just to see garbage
	printf("garbage: %s\n", str);

	str = "abc";
	printf(" before: %s\n",str);

	str = ft_strmapi("abc", change);

	printf("after: %s\n", str);

	free(str);
} */