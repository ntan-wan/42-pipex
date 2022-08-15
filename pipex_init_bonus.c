/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:45:26 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:20 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	clear_all(t_pipex_bonus *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	free(pipex->pipefd_storage);
	print_error_and_exit("envp");
}

void	pipex_init_bonus(int ac, char **envp, t_pipex_bonus *pipex)
{
	pipex->child_index = -1;
	pipex->total_cmds = ac - 3 - pipex->here_doc;
	pipex->total_pipes_ends = 2 * (pipex->total_cmds - 1);
	pipex->pipefd_storage = (int *)malloc(sizeof(int) * pipex->total_pipes_ends);
	if (!pipex->pipefd_storage)
		print_error_and_exit("pipe");
	pipex->env_path = find_envp_path(envp);
	pipex->all_cmd_paths = find_cmd_paths(pipex->env_path);
	if (!pipex->all_cmd_paths)
		clear_all(pipex);
}