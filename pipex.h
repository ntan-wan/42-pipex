/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:13:49 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/12 02:10:36 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	stdlib.h - > exit(int status)
	- we can use EXIT_SUCCESS(has value of 0) or EXIT_FAILURE(has value of 1)
	to pass in for status argument.
	
	sys/stat.h -> S_IRUSR, S_IWUSR, S_IRGRP, S_IWGRP, S_IROTH 
	- These are permisson bit. We give read and write permission to the owner
	of the file, read and write permission to the group, and read
	permission to others.

	errno.h + string.h -> char *strerror(int errnum)
	- Display error message associated with the error number.

	stdio.h -> void perror(const char *s)
	- Print custom message title followed by error
	error message.

	unistd.h -> pid_t fork(void)
	- Allow our process(parent) to create
	new process(child).
 */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		infile;
	int		outfile;
	char	*envp_path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

/* utils */
void	t_pipex_init(int ac, char **av, char **envp, t_pipex *pipex);

/* errors */
void	print_error_and_exit(char *message);
int		is_error(int status);

/* paths */
char	*find_envp_path(char **envp);
char	**find_cmd_paths(char *envp_path);

/* childs */
int		is_child(int status);
#endif
