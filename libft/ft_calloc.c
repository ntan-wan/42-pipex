/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:13:27 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/11 13:13:58 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	rtn = malloc(count * size);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, count * size);
	return (rtn);
}
