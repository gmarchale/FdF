/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:52:50 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/10 15:34:39 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*ret;

	i = 0;
	val = (unsigned char)c;
	ret = b;
	while (i < len)
	{
		ret[i] = val;
		i++;
	}
	return (ret);
}
