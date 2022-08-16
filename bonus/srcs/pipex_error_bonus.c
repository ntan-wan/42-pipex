/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:25:50 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/17 07:26:58 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
