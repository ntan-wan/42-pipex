/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:10:54 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/11 16:11:46 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//
#include <stdio.h>

int	open_file(char *file_name, int type_file)
{
	int		fd;

	if (type_file == INFILE)
	{
		if (access(file_name, F_OK) != 0)
		{
			perror(file_name);
			return (STDIN);
		}
		fd = open(file_name, O_RDONLY);
	}
	else
		fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	return (fd);
}

int	main(int ac, char **av, char **envp)
{
	int		fdin;
	int		fdout;
	char	*cmd_path;

	cmd_path = "";
	//if (ac >= 5)
	//{
		fdin = open_file(av[1], INFILE);
		fdout = open_file(av[ac - 1], OUTFILE);
		//cmd_path = find_cmd_path(envp, av[2]);
		//printf("%s\n", cmd_path);
	//}
	return (0);
}
