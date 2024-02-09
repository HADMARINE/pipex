/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:11 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/22 15:14:04 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pvars *v)
{
	close(v->tube[0]);
	close(v->tube[1]);
}

void	close_files(t_pvars *v)
{
	close(v->infile);
	close(v->outfile);
}

void	free_ftsplit(char **sa)
{
	int	i;

	if (!sa)
		return ;
	i = 0;
	while (sa[i])
	{
		free(sa[i]);
		i++;
	}
	free(sa);
}

void	free_child_process(t_pvars *v)
{
	int	i;

	i = 0;
	while (v->cmdargs[i])
	{
		free(v->cmdargs[i]);
		i++;
	}
	free(v->cmdargs);
	free(v->cmd);
}

void	free_parent_process(t_pvars *v)
{
	int	i;

	i = 0;
	close_files(v);
	free_ftsplit(v->cmdpaths);
}
