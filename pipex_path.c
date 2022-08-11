#include "pipex.h"

char	*find_PATH(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	**find_cmd_paths(char *envp_PATH)
{
	char	**cmd_paths;

	cmd_paths = ft_split(envp_PATH, ':');
	return (cmd_paths);
}