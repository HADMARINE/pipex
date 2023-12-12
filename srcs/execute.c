/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:43:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/12 22:16:01 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(char infile[], char outfile[], char cmd1[], char cmd2[])
{
	t_list	*ifd;

	ifd = get_file_data(infile);
}

void	init_files(char infile[], char outfile[], t_pvars *v)
{
	v->infile = open(infile, O_RDONLY);
	if (v->infile < 0)
		msg_error(E_INFILE);
	v->outfile = open(outfile, O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (v->outfile < 0)
	{
		close(v->infile);
		msg_error(E_OUTFILE);
	}
}
