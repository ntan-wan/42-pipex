/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:44:30 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/18 16:24:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_pipex_bonus
{
	int		infile_fd;
	int		outfile_fd;
	char	*env_path;
	char	**all_cmd_paths;
	char	*cmd_path;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		total_cmds;
	int		total_pipes_ends;
	int		*pipefd_storage;
	int		child_index;
}	t_pipex_bonus;

/* main */
void	close_pipes(t_pipex_bonus *pipex);

/* child */
void	run_childs_process(char **av, char **envp, t_pipex_bonus *p);

/* init */
void	pipex_init_bonus(int ac, char **envp, t_pipex_bonus *pipex);

/* file */
void	get_infile_fd(int ac, char **av, t_pipex_bonus *pipex);
void	get_outfile_fd(int ac, char **av, t_pipex_bonus *pipex);

/* path */
char	*find_envp_path(char **envp);
char	**find_cmd_paths(char *envp_path);
char	*get_cmd_path(char **cmd_paths, char *cmd);

/* error */
int		is_error(int status);
void	print_error_and_exit(char *message);

/* here_doc */
//
int		args_in(char *arg, t_pipex_bonus *pipex);
int		is_here_doc(char *infile);
void	here_doc(int ac, char *argv, t_pipex_bonus *pipex);

/* cmd */
char	**split_cmd(char *cmd);

/* free */
void	free_parent(t_pipex_bonus *pipex);
void	free_child(t_pipex_bonus *pipex);
#endif
