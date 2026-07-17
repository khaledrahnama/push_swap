/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:43:10 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 18:58:17 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}

/*
 using heap memory to solve the
 overlapping memory issue (unefficient solution)
void	*ft_memmove(void *dest,const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i=0;
	unsigned char* temp;
	unsigned char* dest_ptr;
	dest_ptr = (unsigned char*)dest;
	if (!dest && !src)
		return (NULL);
	temp = malloc( n );
	if(!temp)
	return(NULL);
	ft_memcpy(temp,src,n);
	while(i < n)
	{
		dest_ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return(dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	i = 0;
	if (!dest && !src)
		return (NULL);
	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	if (d > s)
	{
		i = n;
		while (i > 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

  #include<stdio.h>
 #include<string.h>
int	main(void)
{
	char str[20] = "abcdef";
	printf("source string: %s \n",str);
	ft_memmove(str + 2, str, 4);
	printf("destination string: %s \n",str);
	char str2[20] = "abcdef";
	printf("source string: %s \n",str2);
	memmove(str2+2, str2,4);
	printf("destination string: %s \n",str2);

}  */