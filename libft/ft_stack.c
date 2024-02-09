/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:41:06 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 15:55:23 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_stack(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_list	*pop_stack(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = *lst;
	*lst = (*lst)->next;
	return (tmp);
}
