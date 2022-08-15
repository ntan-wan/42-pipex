/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:35:00 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 16:58:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_here_doc(char *infile)
{
	if (ft_strncmp("here_doc", infile, 9) == 0)
		return (1);
	return (0);
}

int	args_in(char *arg, t_pipex_bonus *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

//
//if (get_next_line(0, &buf) < 0)
//	exit(EXIT_FAILURE);
void	here_doc(char *limiter, t_pipex_bonus *pipex)
{
	int		temp_fd;
	int		limiter_len;
	char	*temp_file;
	char	*line;

	temp_file = ".heredoc_tmp";
	temp_fd = open(temp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	limiter_len = ft_strlen(limiter);
	if (is_error(temp_fd))
		print_error_and_exit("here_doc");
	while (1)
	{
		write(STDOUT, "heredoc> ", 9);
		line = get_next_line(STDIN);
		if (ft_strncmp(limiter, line, limiter_len) == 0)
			break ;
		write(temp_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(temp_fd);
	pipex->infile_fd = open(temp_file, O_RDONLY);
	if (is_error(pipex->infile_fd))
	{
		unlink(temp_file);
		print_error_and_exit(temp_file);
	}
}
