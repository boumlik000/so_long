/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:31:10 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/29 15:07:46 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base1(unsigned long nbr, char *base, int i)
{
	int				len;
	unsigned long	bs;

	len = 0;
	if (i && !nbr)
		return (ft_putstr1("(nil)"));
	if (i)
		len += ft_putstr1("0x");
	bs = ft_strlen1(base);
	if (nbr >= bs)
		len += ft_putnbr_base1(nbr / bs, base, 0);
	len += ft_putchar1(base[nbr % bs]);
	return (len);
}
