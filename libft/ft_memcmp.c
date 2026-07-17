/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:11:30 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 19:01:50 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;
	while (n--)
	{
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		s1_ptr++;
		s2_ptr++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "abcdffghsdfsdfsdfsdfsdfsdfsdfsdfsdfsdf";
	char s2[] = "abcderwerwerwerewrwererwrwerwerwerwvvsdf";

	printf("%d \n", ft_memcmp(s1, s2, 4));
	printf("%d \n", ft_memcmp(s1, s2, 6));
} */