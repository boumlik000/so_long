/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:31:20 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/01 21:22:16 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar1(va_arg(ap, int));
	else if (c == 's')
		count = ft_putstr1(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr1(va_arg(ap, int));
	else if (c == 'u')
		count = ft_posputnbr1(va_arg(ap, unsigned int));
	else if (c == 'p')
		count += ft_putnbr_base1(va_arg(ap, unsigned long), "0123456789abcdef",
				1);
	else if (c == 'x')
		count = ft_putnbr_base1(va_arg(ap, unsigned int), "0123456789abcdef",
				0);
	else if (c == 'X')
		count = ft_putnbr_base1(va_arg(ap, unsigned int), "0123456789ABCDEF",
				0);
	return (count);
}

int	ft_printf(const char *f, ...)
{
	va_list	argument;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(argument, f);
	if (!f)
		return (-1);
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1] == '\0')
			return (-1);
		else if (f[i] == '%' && f[i + 1] == '%')
			len = len + ft_putchar1(f[i++]);
		else if ((f[i] == '%') && (ft_strchr1("cspdiuxX", f[i + 1]) == 1))
			len = len + check_type(f[++i], argument);
		else
			len = len + ft_putchar1(f[i]);
		i++;
	}
	va_end(argument);
	return (len);
}
