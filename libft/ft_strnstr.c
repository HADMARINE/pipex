/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/09 11:45:38 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	incrementation(char **l, char **bp)
{
	*l += 1;
	*bp += 1;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*bp;
	char	*l;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	b = (char *)big;
	while (len-- > 0 && *b)
	{
		l = (char *)little;
		bp = b;
		if (*l == *bp && *bp && *l)
		{
			incrementation(&l, &bp);
			while (*bp && *l && *l == *bp && (size_t)(l - little) <= len)
				incrementation(&l, &bp);
			if (!*l)
				return (b);
		}
		b++;
	}
	return (NULL);
}

// int main() {
// 	printf("%s", ft_strnstr("aaabcabcd", "cd", 7));
// }