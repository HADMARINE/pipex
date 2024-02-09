/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:18:32 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 15:07:31 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		puthexadecimal(unsigned long long v, short maj);
char	*ft_utoa(unsigned int n);

int	c_exec(va_list *valist)
{
	unsigned char	v;

	v = (unsigned char)va_arg(*valist, int);
	ft_putchar_fd(v, 1);
	return (1);
}

int	s_exec(va_list *valist)
{
	const char	*v;

	v = va_arg(*valist, const char *);
	if (v == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd((char *)v, 1);
	return (ft_strlen(v));
}

int	p_exec(va_list *valist)
{
	unsigned long long	v;
	int					count;

	v = va_arg(*valist, unsigned long long);
	if (v == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	count += puthexadecimal(v, 0);
	return (count);
}

int	d_exec(va_list *valist)
{
	int		v;
	char	*str;
	int		len;

	v = va_arg(*valist, int);
	str = ft_itoa(v);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	u_exec(va_list *valist)
{
	unsigned int	v;
	char			*str;
	int				len;

	v = va_arg(*valist, unsigned int);
	str = ft_utoa(v);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
