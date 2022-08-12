/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:33:13 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/12 15:33:26 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd(char *cmd)
{
	char	**splited_cmd;

	splited_cmd = ft_split(cmd, ' ');
	return (splited_cmd);
}
