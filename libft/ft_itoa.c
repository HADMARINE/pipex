/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:08:50 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/08 14:53:58 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getlength(int n)
{
	int	len;

	len = 2;
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*return_strlcpy(char *str, char *dat, int len)
{
	ft_strlcpy(str, dat, len);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*sp;
	short	isminus;

	str = (char *)malloc(getlength(n) * sizeof(char));
	if (!str)
		return (NULL);
	sp = str + getlength(n) - 1;
	*sp-- = '\0';
	isminus = 0;
	if (n == -2147483648)
		return (return_strlcpy(str, "-2147483648", 12));
	if (n < 0)
	{
		*str = '-';
		n *= -1;
		isminus = 1;
	}
	while (sp - isminus - str >= 0)
	{
		*sp-- = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
