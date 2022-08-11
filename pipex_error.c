#include "pipex.h"

int		is_error(int status)
{
	if (status == -1)
		return (1);
	return (0);
}

void	print_error_and_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}