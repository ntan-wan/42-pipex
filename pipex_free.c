#include "pipex.h"

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	while (pipex->all_cmd_paths[i])
	{
		free(pipex->all_cmd_paths[i]);
		i++;
	}
	free(pipex->all_cmd_paths);
}

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd_path);
}