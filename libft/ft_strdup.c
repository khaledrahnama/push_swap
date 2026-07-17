/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:13:06 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 19:03:58 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*new_string;

	i = 0;
	new_string = malloc(ft_strlen(s) + 1);
	if (!new_string)
		return (NULL);
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*
 char	*ft_strdup(char *src)
{
	char	*copy;
	char	*original_source;
	char	*start_copy;

	original_source = src;
	while (*src)
	{
		src++;
	}
	copy = (char *)malloc(((src - original_source) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	start_copy = copy;
	src = original_source;
	while (*src)
	{
		*copy++ = *src++;
	}
	*copy = '\0';
	return (start_copy);
}


#include <stdio.h>

int	main(void)
{
	const char	*original = "Hello, world!";
	char		*copy;

	copy = ft_strdup(original);
	if (copy)
	{
		printf("Original: %s\n", original);
		printf("Copy: %s\n", copy);
		free(copy); // Don't forget to free the allocated memory
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
 */