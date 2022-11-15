/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:53:02 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/12 15:54:30 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int nbr, int fd)
{
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + 48, fd);
	}
	else
	{
		ft_putunbr_fd(nbr / 10, fd);
		ft_putunbr_fd(nbr % 10, fd);
	}
}
