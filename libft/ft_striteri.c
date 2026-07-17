/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:52:48 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 19:04:08 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	alternate(unsigned int i, char *c)
{
	if (i % 3 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int	main(void)
{
	char str[] = "hello world";

	ft_striteri(str, to_upper);

	printf("%s\n", str);

	char str2[] ="hello world";

	ft_striteri(str2, alternate);

	printf("%s\n", str2);
} */