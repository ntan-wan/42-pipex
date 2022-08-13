/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:35:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/13 10:02:26 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_child(int status)
{
	if (status == 0)
		return (1);
	return (0);
}

void	first_child_process(char **av, char **envp, t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	dup2(pipex->infile_fd, STDIN);
	dup2(pipex->pipefd[1], STDOUT);
	pipex->cmd_args = split_cmd(av[2]);
	pipex->cmd_path = get_cmd_path(pipex->all_cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd_path)
	{
		free_child(pipex);
		print_error_and_exit("command not found");
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}

void	second_child_process(char **av, char **envp, t_pipex *pipex)
{
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], STDIN);
	dup2(pipex->outfile_fd, STDOUT);
	pipex->cmd_args = split_cmd(av[3]);
	pipex->cmd_path = get_cmd_path(pipex->all_cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd_path)
	{
		free_child(pipex);
		print_error_and_exit("command not found");
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}
