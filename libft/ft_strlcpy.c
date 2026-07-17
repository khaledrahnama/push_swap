/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:10:04 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/31 01:29:33 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/* char *ft_strcpy(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while(*src)
	{
		*ptr=*src;
		ptr++;
		src++;
	}
	*ptr='\0';
	return (dest);
}


  char *ft_strlcpy(char *dest, const char *src)
 {
	char *ptr;
	ptr = dest;
	while((*ptr++ = *src++ ));
	return (dest);
 }



 #include<stdio.h>
int	main(void)
{
	char		dest[20] = "Hello, ";
	const char	*src = "world!";

	ft_strcpy(dest, src);
	printf("%s\n", dest); // Output: "Hello, world!"
}







// here strncpy is written and tested
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	while(*src &&  n>0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}
	while(n>0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
	return(dest);
}

#include <stdio.h>

int	main(void)
{
	char		dest[20] = "Hello, ";
	const char	*src = "world!";
		int i;

	i=0;
	ft_strncpy(dest, src , 20);
	printf("%s\n", dest); // Output: "Hello, world!"
	while(i<400)
	{
		printf("index %d : %d \n", i , dest[i]);
		i++;
	}
}

 #include<stdio.h>

int	main(void)
{
	char dest[20] = "Hello, ";
	const char *src = "world!";
	int i;
	i = 0;

	ft_strlcpy(dest, src , sizeof(dest));
	printf("%s\n ", dest);

	while(i<200)
	{
		printf("index %d : %d \n", i , dest[i]);
		i++;
	}
} */