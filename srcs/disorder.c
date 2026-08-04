/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaledrahnama <khaledrahnama@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:43:09 by khaledrahna       #+#    #+#             */
/*   Updated: 2026/08/04 14:43:11 by khaledrahna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_disorder_pct(int scaled, int fd)
{
	ft_putnbr_fd(scaled / 100, fd);
	ft_putstr_fd(".", fd);
	if (scaled % 100 < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(scaled % 100, fd);
	ft_putstr_fd("%", fd);
}