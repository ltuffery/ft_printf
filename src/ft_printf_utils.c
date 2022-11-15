/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:12:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/12 15:58:54 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_putptr(va_list args)
{
	int					len;
	unsigned long long	ptr;

	ptr = va_arg(args, unsigned long long);
	if (ptr != 0)
	{
		len = ft_putstr_fd("0x", 1);
		len += ft_puthexa(ptr, 0);
	}
	else
	{
		len = ft_putstr_fd("(nil)", 1);
	}
	return (len);
}

int	ft_putnbr(va_list args)
{
	int	len;
	int	nbr;

	len = 1;
	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		len++;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int	ft_puthexa(unsigned long long nbr, int is_upper)
{
	int	len;

	ft_puthexa_fd(nbr, is_upper, 1);
	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned int nbr)
{
	int				len;

	len = 1;
	ft_putunbr_fd(nbr, 1);
	while (nbr / 10)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
