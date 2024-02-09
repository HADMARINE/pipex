/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:41:09 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 15:07:37 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	puthexadecimal(unsigned int v, short maj);

int	x_exec(va_list *valist)
{
	unsigned int	v;

	v = va_arg(*valist, unsigned long);
	return (puthexadecimal(v, 0));
}

int	xmaj_exec(va_list *valist)
{
	unsigned int	v;

	v = va_arg(*valist, unsigned long);
	return (puthexadecimal(v, 1));
}

int	percent_exec(va_list *valist)
{
	(void)valist;
	ft_putchar_fd('%', 1);
	return (1);
}
