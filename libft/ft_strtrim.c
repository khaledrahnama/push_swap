/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 21:29:11 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 02:28:20 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + start, end - start);
	str[end - start] = '\0';
	return (str);
}

/*

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*result;

	printf("Test 1: basic trim\n");
	result = ft_strtrim("   hello world   ", " ");
	printf("[%s]\n", result);
	free(result);
	printf("\nTest 2: trim multiple chars\n");
	result = ft_strtrim("xxhelloxxworldxx", "x");
	printf("[%s]\n", result);
	free(result);
	printf("\nTest 3: trim set of chars\n");
	result = ft_strtrim("abcHELLOabc", "abc");
	printf("[%s]\n", result);
	free(result);
	printf("\nTest 4: no trim needed\n");
	result = ft_strtrim("libft", " ");
	printf("[%s]\n", result);
	free(result);
	printf("\nTest 5: full trim (empty result)\n");
	result = ft_strtrim("aaaaaa", "a");
	printf("[%s]\n", result);
	free(result);
	return (0);
}
	*/