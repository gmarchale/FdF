/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:05:54 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/08 16:22:44 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		count = count + 1 + ft_putnbr(-n);
	}
	else if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
		count++;
	}
	else
	{
		count = count + ft_putnbr(n / 10) + ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
		count++;
	}
	else
	{
		count = count + ft_putunsigned(n / 10) + ft_putunsigned(n % 10);
	}
	return (count);
}

int	ft_puthexlow(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 16)
	{
		if (n < 10)
			n += 48;
		else
			n += 87;
		write(1, &n, 1);
		count++;
	}
	else
	{
		count = count + ft_puthexlow(n / 16) + ft_puthexlow(n % 16);
	}
	return (count);
}

int	ft_puthexup(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 16)
	{
		if (n < 10)
			n += 48;
		else
			n += 55;
		write(1, &n, 1);
		count++;
	}
	else
	{
		count = count + ft_puthexup(n / 16) + ft_puthexup(n % 16);
	}
	return (count);
}

int	ft_putptr(unsigned long int n)
{
	int	count;

	count = 0;
	if (n < 16)
	{
		if (n < 10)
			n += 48;
		else
			n += 87;
		write(1, &n, 1);
		count++;
	}
	else
	{
		count = count + ft_putptr(n / 16) + ft_putptr(n % 16);
	}
	return (count);
}
