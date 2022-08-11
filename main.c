/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:10:54 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/12 00:34:17 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_parent_child_process(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (is_child())
		first_child();
	pipex->pid2 = fork();
	if (is_child())
		second_child();
}

int main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	
	if (ac != 5)
	{
		if (ac < 5)
			ft_putstr_fd("Error: too few arguments!\n", 2);
		else if (ac > 5)
			ft_putstr_fd("Error: too many arguments!\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		t_pipex_init(ac, av, envp, &pipex);
		run_parent_child_process(&pipex);
	}
	return (0);
}
