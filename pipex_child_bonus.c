/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:27:23 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 09:17:55 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_child(pid_t pid)
{
	if (pid == 0)
		return (1);
	return (0);
}

static void	redirect_io(int infd, int outfd)
{
	dup2(infd, STDIN);
	dup2(outfd, STDOUT);
}

static void	redirect(t_pipex_bonus *p, int read_end, int write_end)
{
	if (p->child_index == 0)
		redirect_io(p->infile_fd, write_end);
	else if (p->child_index == p->total_cmds - 1)
		redirect_io(read_end, p->outfile_fd);
	else
		redirect_io(read_end, write_end);
}

void	run_childs_process(char **av, char **envp, t_pipex_bonus *p)
{
	int	read_end;
	int	write_end;

	read_end = p->pipefd_storage[2 * p->child_index - 2];
	write_end = p->pipefd_storage[2 * p->child_index + 1];
	p->pid = fork();
	if (is_child(p->pid))
	{
		redirect(p, read_end, write_end);
		close_pipes(p);
		p->cmd_args = split_cmd(av[2 + p->here_doc + p->child_index]);
		p->cmd_path = get_cmd_path(p->all_cmd_paths, p->cmd_args[0]);
		if (!p->cmd_path)
		{
			free_child(p);
			print_error_and_exit("command not found");
		}
		execve(p->cmd_path, p->cmd_args, envp);
	}
}
