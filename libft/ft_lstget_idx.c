/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:43:54 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 16:44:01 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_idx(t_list *lst, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		if (lst->next == NULL)
			return (NULL);
		lst = lst->next;
		i++;
	}
	return (lst);
}
