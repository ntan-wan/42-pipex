/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:08:53 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/15 09:09:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**split_cmd(char *cmd)
{
	char	**splited_cmd;

	splited_cmd = ft_split(cmd, ' ');
	return (splited_cmd);
}
