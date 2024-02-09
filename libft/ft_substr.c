/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:35:18 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/09 17:00:12 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getlen(size_t len, char const *src, unsigned int start)
{
	size_t	srcl;

	srcl = ft_strlen(src + start);
	if (len > srcl)
		return (srcl);
	return (len);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*dest;
	char	*dp;
	char	*mp;
	char	*np;

	if (!src)
		return (NULL);
	if ((unsigned)ft_strlen(src) < start)
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
		return (dest);
	}
	len = getlen(len, src, start);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dp = dest;
	mp = (char *)src + start;
	np = mp + len;
	while (mp != np && *mp && *(np - 1))
		*dp++ = *mp++;
	*dp = '\0';
	return (dest);
}
