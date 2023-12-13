/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:29:12 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/13 12:11:20 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pvars	v;

	if (argc != 5)
		return (msg_error(E_INPUT));
	if (!init_files(argv[1], argv[4], &v))
		return (EXIT_FAILURE);
	if (!init_pipe(&v))
		return (EXIT_FAILURE);
	v.paths = get_path(envp);
	v.cmdpaths = ft_split(v.paths, ':');
	if (!init_processes(&v, argv, envp))
	{
		// free before
		return (EXIT_FAILURE);
	}
	close_pipes(&v);
	waitpid(v.p1, NULL, 0);
	waitpid(v.p2, NULL, 0);
	free_parent_process(&v);
	return (EXIT_SUCCESS);
}
