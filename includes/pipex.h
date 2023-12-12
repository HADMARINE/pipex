/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:29:19 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/12 22:16:16 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Includes

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# include "libft.h"

// Defines

typedef struct s_pvars {
	int		infile;
	int		outfile;
}	t_pvars;

typedef enum e_error {
	E_INPUT = "Input error",
	E_INFILE = "Input file error",
	E_OUTFILE = "Output file error"
}	t_error;

// Function prototypes

int		msg_error(t_error e);
t_list	*get_file_data(const char *filename);
void	init_files(char infile[], char outfile[], t_pvars *v);

#endif