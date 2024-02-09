/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:38:24 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 15:07:53 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	puthexadecimal(unsigned long long v, short maj)
{
	char	lst[17];
	int		count;

	count = 0;
	if (maj == 1)
		ft_strlcpy(lst, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(lst, "0123456789abcdef", 17);
	if (v >= 16)
	{
		count += puthexadecimal(v / (unsigned long long)16, maj);
	}
	ft_putchar_fd(lst[v % (unsigned long long)16], 1);
	count++;
	return (count);
}
