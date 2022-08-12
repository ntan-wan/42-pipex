/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:13:49 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/12 13:23:34 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	stdlib.h - > exit(int status)
	- we can use EXIT_SUCCESS(has value of 0) or EXIT_FAILURE(has value of 1)
	to pass in for status argument.
	
	stdio.h -> void perror(const char *s)
	- Print custom message title followed by error
	error message.

	unistd.h -> pid_t fork(void), execve() ...

	fcntl.h -> open(), close() ...
 */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		infile_fd;
	int		outfile_fd;
	char	*envp_path;
	char	**all_cmd_paths;
	char	**cmd_args;
	char	*cmd_path;
}t_pipex;

/* init */
void	s_pipex_init(int ac, char **av, char **envp, t_pipex *pipex);

/* errors */
int		is_error(int status);
void	print_error_and_exit(char *message);

/* paths */
char	*find_envp_path(char **envp);
char	**find_cmd_paths(char *envp_path);
char	*get_cmd_path(char **cmd_paths, char *cmd);

/* childs */
int		is_child(int status);
void	first_child_process(char **av, char **envp, t_pipex *pipex);
void	second_child_process(char **av, char **envp, t_pipex *pipex);

/* cmd */
char	**split_cmd(char *cmd);

/* free */
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);

#endif
