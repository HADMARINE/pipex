/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:29:19 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/13 12:11:03 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Includes

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

# include "libft.h"

// Defines

typedef struct s_pvars {
	int		infile;
	int		outfile;
	int		tube[2];
	char	*paths;
	char	**cmdpaths;
	char	**cmdargs;
	char	*cmd;
	pid_t	p1;
	pid_t	p2;
}	t_pvars;

# define E_INPUT "Input error"
# define E_INFILE "Input file error"
# define E_OUTFILE "Output file error"
# define E_PIPEINIT "Pipe init error"
# define E_COMMAND "Command not found"

// Function prototypes

int		msg_error(char *e);
bool	init_files(char infile[], char outfile[], t_pvars *v);
bool	init_pipe(t_pvars *v);
bool	init_processes(t_pvars *v, char *argv[], char *envp[]);
char	*get_path(char *envp[]);
void	close_pipes(t_pvars *v);
void	free_child_process(t_pvars *v);
void	free_parent_process(t_pvars *v);
void	first_child(t_pvars *v, char *argv[], char *envp[]);
void	second_child(t_pvars *v, char *argv[], char *envp[]);
char	*getcmd(char **paths, char *cmd);

#endif