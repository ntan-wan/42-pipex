/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:35:02 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/17 07:23:00 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_error(int status)
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
