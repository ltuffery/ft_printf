/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:09:34 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/12 15:50:01 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_format(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'c')
		len = ft_putchar_fd((unsigned char) va_arg(args, int), 1);
	else if (format == 'd' || format == 'i')
		len = ft_putnbr(args);
	else if (format == 'x')
		len = ft_puthexa(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len = ft_puthexa(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		len = ft_putptr(args);
	else if (format == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else
		len = ft_putchar_fd(format, 1);
	return (len);
}

int	ft_parsing(const char *str, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_format(str[i + 1], args);
			i++;
		}
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = ft_parsing(str, args);
	va_end(args);
	return (len);
}
