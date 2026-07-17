/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:29:14 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 03:36:22 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char)dest;
	s = (unsigned char) src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

int	main(void)
{
	char	dest1[4];
	char	dest2[4];
	size_t	n;

	char src[]="abcd";
	n = 2;
	printf("dest before: %s \n", dest1);
	ft_memcpy(dest1,src,n);
	printf("dest after: %s \n",dest1);
	printf("dest before: %s \n", dest2);
	memcpy(dest2,src,n);
	printf("dest after: %s \n",dest2);
}
	*/

/* #include<stdio.h>
int	main(void)
{
	char str[20] = "abcdef";
	printf("source string: %s \n",str);
	ft_memmove(str + 2, str, 4);
	printf("destination string: %s",str);

}  */