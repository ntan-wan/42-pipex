#include "pipex.h"

int	is_child(int status)
{
	if (status == 0)
		return (1);
	return (0);
}