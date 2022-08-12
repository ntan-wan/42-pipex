#include "pipex.h"

char	**split_cmd(char *cmd)
{
	char	**splited_cmd;

	splited_cmd = ft_split(cmd, ' ');
	return (splited_cmd);
}