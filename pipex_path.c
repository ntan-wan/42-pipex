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
