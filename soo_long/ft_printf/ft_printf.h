/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:31:23 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/29 15:10:24 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar1(int c);
int	ft_putstr1(char *str);
int	ft_putnbr1(int n);
int	ft_posputnbr1(unsigned int n);
int	ft_putnbr_base1(unsigned long nbr, char *base, int i);
int	ft_strlen1(const char *str);
int	ft_strchr1(const char *s, int c);
int	ft_printf(const char *f, ...);

#endif
