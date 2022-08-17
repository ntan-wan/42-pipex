/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:35:00 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/17 13:33:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	is_here_doc(char *infile)
{
	if (ft_strncmp("here_doc", infile, 9) == 0)
		return (1);
	return (0);
}

static void	here_doc_process(char *limiter, char **line, int temp_fd)
{
	int		limiter_len;
	char	*limiter_with_null;

	limiter_len = ft_strlen(limiter);
	limiter_with_null = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(STDOUT, "heredoc> ", 9);
		*line = get_next_line(STDIN);
		if (ft_strncmp(limiter_with_null, *line, limiter_len + 1) == 0)
			break ;
		write(temp_fd, *line, ft_strlen(*line));
		free(*line);
	}	
	free(limiter_with_null);
	free(*line);
	close(temp_fd);
}

void	here_doc(char *limiter, t_pipex_bonus *pipex)
{
	int		temp_fd;
	char	*temp_file;
	char	*line;

	temp_file = ".heredoc_tmp";
	temp_fd = open(temp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (is_error(temp_fd))
		print_error_and_exit("here_doc");
	here_doc_process(limiter, &line, temp_fd);
	pipex->infile_fd = open(temp_file, O_RDONLY);
	if (is_error(pipex->infile_fd))
	{
		unlink(temp_file);
		print_error_and_exit(temp_file);
	}
}
