/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:29:12 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/12 22:22:32 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_pvars	v;

	if (argc != 5)
		return (msg_error(E_INPUT));
	init_files(argv[1], argv[4], &v);
	return (EXIT_SUCCESS);
}
