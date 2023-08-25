/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livieira <livieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:03:13 by livieira          #+#    #+#             */
/*   Updated: 2023/08/25 04:59:25 by livieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_getline(rest);
	rest = ft_get_rest(rest);
	return (line);
}
