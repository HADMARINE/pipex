/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:46:46 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/08 16:05:44 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	if (dest == src || size == 0)
		return (dest);
	if (dest > src && dest - src < (long)size)
	{
		d = (char *)dest + size - 1;
		s = (char *)src + size - 1;
		while (size--)
		{
			*d-- = *s--;
		}
		return (dest);
	}
	d = (char *)dest;
	s = (char *)src;
	return (ft_memcpy(dest, src, size));
}
