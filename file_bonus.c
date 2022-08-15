/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:15:12 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 17:27:32 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_infile_fd(char **av, t_pipex_bonus *pipex)
{
	char	*infile;
	char	*limiter;

	infile = av[1];
	limiter = av[2];
	if (is_here_doc(infile))
	{
		//
		pipex->here_doc = 1;
		here_doc(limiter, pipex);
	}
	else
	{
		pipex->infile_fd = open(infile, O_RDONLY);
		if (is_error(pipex->infile_fd))
			print_error_and_exit(infile);
	}
}

void	get_outfile_fd(int ac, char **av, t_pipex_bonus *pipex)
{
	char *outfile;

	outfile = av[ac - 1];
	if (pipex->here_doc)
		pipex->outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		pipex->outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (is_error(pipex->outfile_fd))
		print_error_and_exit(outfile);
}
