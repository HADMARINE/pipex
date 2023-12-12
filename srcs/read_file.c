/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:54:11 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/12 16:36:19 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*get_file_data(const char *filename)
{
	t_list	*lst;
	int		fd;
	char	*s;

	lst = NULL;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(s));
		s = get_next_line(fd);
	}
	return (lst);
}
