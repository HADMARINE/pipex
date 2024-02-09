/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:49:53 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 16:11:11 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lp;
	t_list	*lp2;

	if (!lst || !del)
		return ;
	lp = *lst;
	while (lp)
	{
		if (del != NULL)
			del(lp->content);
		lp2 = lp->next;
		free(lp);
		lp = lp2;
	}
	*lst = NULL;
}
