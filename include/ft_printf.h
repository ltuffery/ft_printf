/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:46:01 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/12 15:55:58 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define ARGS "cspdiuxX%"

int	ft_printf(const char *str, ...);
int	ft_putptr(va_list args);
int	ft_puthexa(unsigned long long nbr, int is_upper);
int	ft_putnbr(va_list args);
int	ft_putunbr(unsigned int nbr);

#endif
