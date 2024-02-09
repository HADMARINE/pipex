/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:11:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/08 12:00:52 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	while (size--)
	{
		if (*(unsigned char *)p1 != *(unsigned char *)p2)
		{
			return (*(unsigned char *)p1 - *(unsigned char *)p2);
		}
		p1++;
		p2++;
	}
	return (0);
}
