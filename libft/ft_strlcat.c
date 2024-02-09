/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:19 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/09 14:43:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	dest_len;
	size_t	n;

	d = dest;
	n = size;
	s = (char *)src;
	while (n-- != 0 && *d != '\0')
		d++;
	dest_len = d - dest;
	n = size - dest_len;
	if (n == 0)
		return (dest_len + get_size(src));
	while (*src != '\0')
	{
		if (n != 1)
		{
			*d++ = *src;
			n--;
		}
		src++;
	}
	*d = '\0';
	return (dest_len + (src - s));
}
