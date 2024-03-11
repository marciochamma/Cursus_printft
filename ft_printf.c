/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:36:45 by mchamma           #+#    #+#             */
/*   Updated: 2023/08/23 14:04:12 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char format, char flag, va_list args)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int), flag);
	else if (format == 'u')
		count += ft_putunsign_base(va_arg(args, unsigned int), format, flag);
	else if (format == 'x')
		count += ft_putunsign_base(va_arg(args, unsigned int), format, flag);
	else if (format == 'X')
		count += ft_putunsign_base(va_arg(args, unsigned int), format, flag);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == '#' || str[i] == '+' || str[i] == ' ')
				i++;
			count += ft_control(str[i], str[i - 1], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		count;
// 	int		a;

// 	a = -20;
// 	count = ft_printf("% d", a);
// 	ft_printf(" -> tamanho: %d\n", count);
// 	count = printf("% d", a);
// 	printf(" -> tamanho: %d\n", count);
// 	return (0);
// }
