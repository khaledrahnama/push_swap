/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:12:39 by krahnama          #+#    #+#             */
/*   Updated: 2026/05/30 20:43:44 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
/*
#include <stdio.h>

int	main(void)
{
	const char *str = "   -12345";
	const char *str2 = "   +67890";
	const char *str3 = "   42abc";
	const char *str4 = "   abc42";

	int num = ft_atoi(str);
	printf("The integer value is: %d\n", num);
	int num2 = ft_atoi("-2147483648");
	printf("The integer value is: %d\n", num2);


	return (0);
}  */