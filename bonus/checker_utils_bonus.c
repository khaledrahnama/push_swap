/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krahnama <krahnama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:19:27 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/07 00:01:03 by krahnama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_memcpy_local(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*read_stdin(void)
{
	char	buf[1024];
	char	*result;
	char	*tmp;
	int		bytes;
	int		res_len;

	result = malloc(1);
	result[0] = '\0';
	res_len = 0;
	bytes = read(0, buf, 1024);
	while (bytes > 0)
	{
		tmp = malloc(res_len + bytes + 1);
		if (!tmp)
			error_exit();
		ft_memcpy_local(tmp, result, res_len);
		ft_memcpy_local(tmp + res_len, buf, bytes);
		tmp[res_len + bytes] = '\0';
		free(result);
		result = tmp;
		res_len += bytes;
		bytes = read(0, buf, 1024);
	}
	return (result);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->size)
	{
		if (a->data[i] < a->data[i - 1])
			return (0);
		i++;
	}
	return (1);
}
