/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:57:35 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 15:06:50 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counter(const char *str)
{
	char			*sp;
	char			tmpch;
	unsigned int	len;

	len = 0;
	sp = (char *)str;
	while (*sp)
	{
		if (*sp == '%' && *(sp + 1))
		{
			tmpch = *ft_strchr("cspdiuxX%", *(sp + 1));
			if (tmpch != '\0')
			{
				sp++;
				len++;
			}
		}
		sp++;
	}
	return (len);
}
