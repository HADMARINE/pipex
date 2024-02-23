/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_many.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:47:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/12 12:05:57 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_many(int num, ...)
{
	va_list	valist;
	char	*s;
	char	*ts;
	int		i;

	va_start(valist, num);
	if (num == 1)
	{
		ts = NULL;
		s = va_arg(valist, char *);
		ft_strlcpy(ts, s, ft_strlen(s));
		return (s);
	}
	i = 1;
	s = va_arg(valist, char *);
	while (i < num)
	{
		ts = ft_strjoin(s, va_arg(valist, char *));
		if (i != 1)
			free(s);
		s = ts;
		i++;
	}
	return (s);
}
