/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:49:25 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 03:54:51 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

size_t	word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_split(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static char	*make_word(char const *s, size_t *i, char c)
{
	size_t	len;
	size_t	j;
	char	*word;

	while (s[*i] == c)
		(*i)++;
	len = word_length(s + *i, c);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
		word[j++] = s[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	w;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	w = 0;
	while (w < count)
	{
		res[w] = make_word(s, &i, c);
		if (!res[w])
			return (free_split(res, w), NULL);
		w++;
	}
	res[w] = NULL;
	return (res);
}

/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	**split;
	size_t	i;

	printf("Test 1\n");
	split = ft_split("Khaled RAHNAMA now is being evaluated", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("[%s]\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("\nTest 2\n");
	split = ft_split("     some random values 233  ", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("[%s]\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
	*/
