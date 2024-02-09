/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:39 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/08 16:09:38 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	char	*c;

	c = (char *)str;
	if (ch == 0)
	{
		while (*c != '\0')
		{
			c++;
		}
		return (c);
	}
	while (*c != '\0')
	{
		if (*(unsigned char *)c == (unsigned char)ch)
		{
			return (c);
		}
		c++;
	}
	return (0);
}
