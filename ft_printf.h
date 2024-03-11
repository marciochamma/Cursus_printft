/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:56:05 by mchamma           #+#    #+#             */
/*   Updated: 2023/06/22 09:56:36 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_control(char format, char flag, va_list args);

int	ft_printf(const char *str, ...);

int	ft_putchar(int c);

int	ft_putstr(char *s);

int	ft_putptr(unsigned long address);

int	ft_putnbr(int n, char flag);

int	ft_putunsign_base(unsigned int n, char format, char flag);

#endif