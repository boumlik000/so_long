/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posputnbr1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:31:05 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/29 15:05:33 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_posputnbr1(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = len + ft_posputnbr1(n / 10);
		len = len + ft_putchar1((n % 10) + 48);
	}
	else
		len = len + ft_putchar1(n + 48);
	return (len);
}
