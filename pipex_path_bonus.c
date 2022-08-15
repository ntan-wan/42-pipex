/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:44:23 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 18:44:26 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_envp_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	**find_cmd_paths(char *envp_path)
{
	char	**cmd_paths;

	cmd_paths = ft_split(envp_path, ':');
	return (cmd_paths);
}

char	*get_cmd_path(char **cmd_paths, char *cmd)
{
	char	*useable_path;
	char	*command_path;

	while (*cmd_paths)
	{
		useable_path = ft_strjoin(*cmd_paths, "/");
		command_path = ft_strjoin(useable_path, cmd);
		free(useable_path);
		if (access(command_path, F_OK | X_OK) == 0)
			return (command_path);
		free(command_path);
		cmd_paths++;
	}
	return (NULL);
}
