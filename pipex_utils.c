#include "pipex.h"

void	free_strs(char	*str, char **strs)
{
	int	i;

	if (str)
	{
		free(str);
		str = NULL;
	}
	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}