/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:10:54 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/13 10:08:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(t_pipex *pipex)
{
	int	pipe_status;

	pipe_status = pipe(pipex->pipefd);
	if (is_error(pipe_status))
		print_error_and_exit("pipe");
}

void	run_childs_process(char **av, char **envp, t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (is_child(pipex ->pid1))
		first_child_process(av, envp, pipex);
	pipex->pid2 = fork();
	if (is_child(pipex->pid2))
		second_child_process(av, envp, pipex);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

void	wait_childs_process(t_pipex *pipex)
{
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		if (ac < 5)
			ft_putstr_fd("Error: too few arguments!\n", STDERR);
		else if (ac > 5)
			ft_putstr_fd("Error: too many arguments!\n", STDERR);
		exit(EXIT_FAILURE);
	}
	else
	{
		s_pipex_init(ac, av, envp, &pipex);
		create_pipe(&pipex);
		run_childs_process(av, envp, &pipex);
		close_pipe(&pipex);
		wait_childs_process(&pipex);
		free_parent(&pipex);
	}
	return (0);
}
