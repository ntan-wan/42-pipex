/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 07:25:00 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 14:44:10 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_parent(t_pipex_bonus *pipex)
{
	int	i;

	i = 0;
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	while (pipex->all_cmd_paths[i])
	{
		free(pipex->all_cmd_paths[i]);
		i++;
	}
	free(pipex->all_cmd_paths);
	free(pipex->pipefd_storage);
}

 void	free_child(t_pipex_bonus *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd_path);
}