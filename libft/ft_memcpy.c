/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:36:33 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/10 11:45:44 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	if (!dest && !src && size != 0)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (size--)
	{
		*d++ = *s++;
	}
	return (dest);
}
