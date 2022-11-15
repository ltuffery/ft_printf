/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:39:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/12 15:41:37 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa_fd(unsigned long long n, int is_upper, int fd)
{
	char	*base;

	if (is_upper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexa_fd(n / 16, is_upper, fd);
		ft_puthexa_fd(n % 16, is_upper, fd);
	}
	else
		ft_putchar_fd(base[n], fd);
}
