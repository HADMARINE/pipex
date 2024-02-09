/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:59:03 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/09 14:04:54 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*dp;
	const char	*sp;
	size_t		s;

	dp = dest;
	sp = src;
	s = size;
	if (s != 0)
	{
		while (--s != 0)
		{
			*dp = *sp;
			if (*sp++ == '\0' || *dp++ == '\0')
				break ;
		}
	}
	if (s == 0)
	{
		if (size != 0)
			*dp = '\0';
		while (*sp++)
			;
	}
	return (sp - src - 1);
}
