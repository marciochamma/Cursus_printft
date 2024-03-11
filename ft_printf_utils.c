/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:12:01 by mchamma           #+#    #+#             */
/*   Updated: 2023/08/23 13:21:48 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_putptr(unsigned long address)
{
	int	count;

	count = 1;
	if (!address)
		return (ft_putstr("(nil)"));
	if (address < 16)
	{
		ft_putstr("0x");
		count += 2;
	}
	else
		count += ft_putptr(address / 16);
	write(1, &"0123456789abcdef"[address % 16], 1);
	return (count);
}

int	ft_putnbr(int n, char flag)
{
	int	unit;
	int	count;

	count = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		unit = (n % 10) * -1 + '0';
		n /= -10;
	}
	else
	{
		if (n >= 0 && (flag == '+' || flag == ' '))
			count += ft_putchar(flag);
		unit = (n % 10) + '0';
		n /= 10;
	}
	flag = 0;
	if (n > 0)
		count += ft_putnbr(n, flag);
	write(1, &unit, 1);
	return (count);
}

int	ft_putunsign_base(unsigned int n, char format, char flag)
{
	size_t	count;
	size_t	base;
	char	*tab;

	base = 10;
	tab = "0123456789abcdef0x";
	if (format == 'x' || format == 'X')
		base = 16;
	if (format == 'X')
		tab = "0123456789ABCDEF0X";
	count = 1;
	if (n && flag == '#')
		count += ft_putstr(&tab[16]);
	flag = 0;
	if (n >= base)
		count += ft_putunsign_base(n / base, format, flag);
	write(1, &tab[n % base], 1);
	return (count);
}
