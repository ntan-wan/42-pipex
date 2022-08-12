/* 
	1. open(..., 0644)
	-  "0644" is the permission bit.
	-  The first digit '0' in "0644" selects the set user ID on execution (4) 
	   and set group ID on execution (2) and sticky (1) attributes.
	   When an executable file's setuid permission is set, users may execute 
	   that program with a level of access that matches the user who owns the 
	   file.

	Example :
	(ugs = set user ID, set group ID, sticky)
	decimal ->		"0"		"6"		 "4"	 "4"
	binary  ->		"000"	"110"	"100"	"100"
	permission ->	"ugs"	"rwx"	"rwx"	"rwx"
	who ->					user	group	others
 */

#include "pipex.h"

void	s_pipex_init(int ac, char **av, char **envp, t_pipex *pipex)
{
	char	*infile;
	char	*outfile;

	infile = av[1];
	outfile = av[ac - 1];
	pipex->infile_fd = open(infile, O_RDONLY);
	if (is_error(pipex->infile_fd))
		print_error_and_exit(infile);
	pipex->outfile_fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (is_error(pipex->outfile_fd))
		print_error_and_exit(outfile);
	pipex->envp_path = find_envp_path(envp);
	pipex->all_cmd_paths = find_cmd_paths(pipex->envp_path);
}