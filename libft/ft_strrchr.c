/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:45 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/10 11:42:35 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*c;
	int		len;

	len = ft_strlen(str);
	if (ch == '\0')
		return ((char *)str + len);
	c = (char *)str + len - 1;
	while (len--)
	{
		if (*(unsigned char *)c == (unsigned char)ch)
		{
			return (c);
		}
		c--;
	}
	return (NULL);
}
