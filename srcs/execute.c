/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:43:02 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/24 00:21:34 by lhojoon          ###   ########.fr       */
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

char	*get_path(char *envp[], char *env)
{
	while (ft_strncmp(env, *envp, ft_strlen(env)))
		envp++;
	return (*envp + (ft_strlen(env) + 1));
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

char	*getcmd(char **paths, char *cmd, char *envp[])
{
	char	*tmp;
	char	*c;

	if (ft_strncmp(cmd, "./", 2) == 0)
	{
		tmp = ft_strjoin_many(3, get_path(envp, "HOME"), "/", cmd);
		if (access(cmd, 0) == 0)
			return (cmd);
	}
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
