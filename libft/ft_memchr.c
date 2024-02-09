/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:05 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/10 11:43:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *blck, int ch, size_t size)
{
	char	*p;

	p = (char *)blck;
	while (size--)
	{
		if ((unsigned char)*p == (unsigned char)ch)
		{
			return (p);
		}
		p++;
	}
	return (NULL);
}
