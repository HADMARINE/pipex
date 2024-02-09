/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:39:22 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/07 16:22:37 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int v, size_t len)
{
	unsigned char	*p;

	p = ptr;
	while (len--)
	{
		*(p++) = (unsigned char)v;
	}
	return (ptr);
}
