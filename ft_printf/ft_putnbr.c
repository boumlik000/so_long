/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:31:14 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/29 15:05:41 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr1(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len = len + ft_putchar1('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		len = len + ft_putnbr1(nb / 10);
		len = len + ft_putchar1((nb % 10) + 48);
	}
	else
		len = len + ft_putchar1(nb + 48);
	return (len);
}
