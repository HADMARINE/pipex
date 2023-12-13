/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:11 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/13 10:46:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pvars *v)
{
	close(v->tube[0]);
	close(v->tube[1]);
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
	close(v->infile);
	close(v->outfile);
	while (v->cmdpaths[i])
	{
		free(v->cmdpaths[i]);
		i++;
	}
	free(v->cmdpaths);
}
