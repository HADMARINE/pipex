/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:43:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/13 12:11:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	init_files(char infile[], char outfile[], t_pvars *v)
{
	v->infile = open(infile, O_RDONLY);
	if (v->infile < 0)
	{
		perror(E_INFILE);
		return (false);
	}
	v->outfile = open(outfile, O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (v->outfile < 0)
	{
		close(v->infile);
		perror(E_OUTFILE);
		return (false);
	}
	return (true);
}

bool	init_pipe(t_pvars *v)
{
	if (pipe(v->tube) < 0)
	{
		perror(E_PIPEINIT);
		return (false);
	}
	return (true);
}

char	*get_path(char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

bool	init_processes(t_pvars *v, char *argv[], char *envp[])
{
	v->p1 = fork();
	if (v->p1 == 0)
		first_child(v, argv, envp);
	v->p2 = fork();
	if (v->p2 == 0)
		second_child(v, argv, envp);
	return (true);
}

char	*getcmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*c;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		c = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(c, 0) == 0)
			return (c);
		free(c);
		paths++;
	}
	return (NULL);
}
