/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:59:43 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/16 11:23:24 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contains(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*getblankstr(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	*str = '\0';
	return (str);
}

void	iter(char const **end, char const **start, char **rp)
{
	while (*end != *start - 1)
		*(*rp)++ = *(*start)++;
	**rp = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*res;
	char		*rp;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start)
	{
		if (contains(*start, set) == 0)
			break ;
		start++;
	}
	while (contains(*end, set) == 1 && start != end)
		end--;
	if (end - start < 0)
		return (getblankstr());
	res = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	rp = res;
	iter(&end, &start, &rp);
	return (res);
}
