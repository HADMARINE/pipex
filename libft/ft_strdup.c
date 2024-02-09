/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:13 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/09 12:55:34 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	char	*p;
	char	*sp;

	s = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!s)
		return (NULL);
	p = (char *)src;
	sp = s;
	while (*p)
	{
		*sp++ = *p++;
	}
	*sp = '\0';
	return (s);
}
