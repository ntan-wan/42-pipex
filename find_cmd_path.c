/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:11:03 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/11 15:11:06 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//
//#include <stdio.h>

char	*find_PATH(char **envp)
{
	char	*envp_PATH;
	int		i;

	i = 0;
	while (envp[i])
	{
		envp_PATH = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_PATH)
		{
			envp_PATH = ft_substr(envp_PATH, 5, ft_strlen(envp_PATH));
			break ;
		}
		i++;
	}
	return (envp_PATH);
}

char **make_usable_paths(char *envp_PATH)
{
	char	**paths;
	char	*temp;
	int		i;

	paths = ft_split(envp_PATH, ':');
	i = 0;
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free_strs(temp, NULL);
		i++;
	}
	return (paths);
}

char	*find_right_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		// if (!cmd_path) ...
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_strs(cmd_path, NULL);
		i++;
	}
	return (NULL);
}

char    *find_cmd_path(char **envp, char *cmd)
{
	char	*envp_PATH;
	char	**paths;
	char	*path;

	//Remember to free() these pointers.	
	envp_PATH = find_PATH(envp);
	paths = make_usable_paths(envp_PATH);
	path = find_right_path(paths, cmd);
	//free_strs(envp_PATH, paths);
	return (path);
}