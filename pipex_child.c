/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:35:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/16 11:51:55 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_child(pid_t pid)
{
	if (pid == 0)
		return (1);
	return (0);
}

void	first_child_process(char **av, char **envp, t_pipex *pipex)
{
	dup2(pipex->infile_fd, STDIN);
	dup2(pipex->pipefd[1], STDOUT);
	close_pipe(pipex);
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
	dup2(pipex->pipefd[0], STDIN);
	dup2(pipex->outfile_fd, STDOUT);
	close_pipe(pipex);
	pipex->cmd_args = split_cmd(av[3]);
	pipex->cmd_path = get_cmd_path(pipex->all_cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd_path)
	{
		free_child(pipex);
		print_error_and_exit("command not found");
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}
