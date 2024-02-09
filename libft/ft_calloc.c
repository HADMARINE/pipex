/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:19:01 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/09 12:52:50 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bloc;

	if (count == 0 || size == 0)
	{
		bloc = malloc(sizeof(char));
		if (!bloc)
			return (NULL);
		*(char *)bloc = '\0';
		return (bloc);
	}
	if ((unsigned)count != count || (unsigned)size != size)
		return (NULL);
	bloc = malloc(count * size);
	if (bloc)
		ft_bzero(bloc, count * size);
	return (bloc);
}
