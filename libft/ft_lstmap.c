/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:57:16 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/10 15:06:37 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*reslst;
	t_list	*rp;

	if (!lst || !f || !del)
		return (NULL);
	reslst = ft_lstnew(f(lst->content));
	rp = reslst;
	lst = lst->next;
	while (lst)
	{
		reslst->next = ft_lstnew(f(lst->content));
		if (!reslst->next)
		{
			ft_lstclear(&rp, del);
			return (NULL);
		}
		reslst = reslst->next;
		lst = lst->next;
	}
	reslst->next = NULL;
	return (rp);
}
