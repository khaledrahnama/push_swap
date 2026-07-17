/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:39:48 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/05/30 21:14:11 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		substr[j] = s[start + j];
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}


#include <stdio.h>

int	main(void)
{
	const char		*str = "Hello, world!";
	unsigned int	start;
	size_t			len;
	char			*result;

	start = 7;
	len = 5;
	result = ft_substr(str, start, len);
	if (result)
	{
		printf("Substring: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
	*/