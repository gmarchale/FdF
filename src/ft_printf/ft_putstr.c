/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:08:16 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/08 16:10:39 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	c;

	c = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[c])
	{
		ft_putchar(str[c]);
		c++;
	}
	return (c);
}
