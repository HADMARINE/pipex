/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:02:46 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/24 00:22:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pvars *v, char *argv[], char *envp[])
{
	dup2(v->tube[1], 1);
	close(v->tube[0]);
	dup2(v->infile, 0);
	v->cmdargs = ft_split(argv[2], ' ');
	v->cmd = getcmd(v->cmdpaths, v->cmdargs[0], envp);
	if (!v->cmd)
	{
		free_child_process(v);
		perror(E_COMMAND);
		exit(EXIT_FAILURE);
	}
	execve(v->cmd, v->cmdargs, envp);
}

void	second_child(t_pvars *v, char *argv[], char *envp[])
{
	dup2(v->tube[0], 0);
	close(v->tube[1]);
	dup2(v->outfile, 1);
	v->cmdargs = ft_split(argv[3], ' ');
	v->cmd = getcmd(v->cmdpaths, v->cmdargs[0], envp);
	if (!v->cmd)
	{
		free_child_process(v);
		perror(E_COMMAND);
		exit(EXIT_FAILURE);
	}
	execve(v->cmd, v->cmdargs, envp);
}
