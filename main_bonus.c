/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:40:52 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 17:58:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	create_pipes(t_pipex_bonus *pipex)
{
	int	i;
	int	pipe_status;
	int	*ptr_to_pipefd;

	i = 0;
	while (pipex->total_cmds - 1 > i)
	{
		ptr_to_pipefd = pipex->pipefd_storage + (i * 2);
		pipe_status = pipe(ptr_to_pipefd);
		if (is_error(pipe_status))
			free_parent(pipex);
		i++;
	}
}

void	close_pipes(t_pipex_bonus *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->total_pipes_ends)
	{
		close(pipex->pipefd_storage[i]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex_bonus	pipex;

	if (ac < 5)
	{
		ft_putstr_fd("Error: too few arguments!\n", STDERR);
		exit(EXIT_FAILURE);
	}
	else
	{
		get_infile_fd(av, &pipex);
		get_outfile_fd(ac, av, &pipex);
		pipex_init_bonus(ac, envp, &pipex);
		create_pipes(&pipex);
		while (++(pipex.child_index) < pipex.total_cmds)
			run_childs_process(av, envp, &pipex);
		waitpid(-1, NULL, 0);
		free_parent(&pipex);
	}
	return (0);
}
