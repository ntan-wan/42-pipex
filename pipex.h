/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:13:49 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/11 15:56:35 by ntan-wan         ###   ########.fr       */
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
 */

#ifndef PIPEX_H
# define PIPEX_H

# define OUTFILE 0 
# define INFILE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

char	*find_cmd_path(char **envp, char *cmd);

/* utils */
void	free_strs(char *str, char **strs);
#endif
