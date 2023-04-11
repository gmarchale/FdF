/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:40:57 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/10 14:27:18 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(char format, va_list argument);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	i = 0;
	count = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (!str)
			return (0);
		else if (str[i] == '%')
		{
			i++;
			count += ft_checkformat(str[i], arguments);
		}
		else
		{
			count++;
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arguments);
	return (count);
}

static int	ft_checkformat(char format, va_list arguments)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		count += ft_putstr(va_arg(arguments, char *));
	else if (format == 'p')
	{
		write(1, "0x", 2);
		count += 2 + ft_putptr(va_arg(arguments, unsigned long));
	}
	else if (format == 'd')
		count += ft_putnbr(va_arg(arguments, int));
	else if (format == 'i')
		count += ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(arguments, unsigned int));
	else if (format == 'x')
		count += ft_puthexlow(va_arg(arguments, unsigned int));
	else if (format == 'X')
		count += ft_puthexup(va_arg(arguments, unsigned int));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}
