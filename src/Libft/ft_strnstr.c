/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:19:42 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/06 15:27:25 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = -1;
	ret = (char *) haystack;
	if (ft_strlen(needle) == 0)
		return (ret);
	if (len == 0)
		return (0);
	while (haystack[++i])
	{
		j = -1;
		while (needle[++j])
		{
			if (haystack[i + j] == needle[j] && i + j < len)
			{
				if (j == ft_strlen(needle) - 1)
					return (&ret[i]);
			}
			else
				break ;
		}
	}
	return (0);
}
