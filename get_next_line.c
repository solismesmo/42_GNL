/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livieira <livieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:03:13 by livieira          #+#    #+#             */
/*   Updated: 2023/08/27 05:33:39 by livieira         ###   ########.fr       */
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
	rest = ft_getrest(rest);
	return (line);
}

char	*ft_read(int fd, char *rest)
{
	char	*buf;
	char	*temp;
	long	past_read;

	buf = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buf)
		return (NULL);
	temp = NULL;
	while (ft_strchr(rest, '\n') == 0)
	{
		past_read = read(fd, buf, BUFFER_SIZE);
		if (past_read == 0)
		{
			free(buf);
			return (rest);
		}
		if (ft_validate(past_read, rest, buf, temp) == 1)
			return (NULL);
		temp = rest;
		buf[past_read] = '\0';
		rest = ft_strjoin(rest, buf);
		free(temp);
	}
	free(buf);
	return (rest);
}

int	ft_validate(long past_read, char *aux, char *buf, char *temp)
{
	if ((aux != NULL && aux[0] == '\0') || (past_read == -1))
	{
		free(temp);
		free(buf);
		free(aux);
		return (1);
	}
	return (0);
}

char	*ft_getline(char *str)
{
	char	*aux;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while ((str[len] != '\n') && (str[len] != '\0'))
		len++;
	aux = ft_substr(str, i, len + 1);
	return (aux);
}

char	*ft_getrest(char *str)
{
	char	*aux;
	int		i;
	int		len;

	len = 0;
	i = ft_strlen(str);
	while ((str[len] != '\n') && (str[len] != '\0'))
		len++;
	if (str[len] == '\n')
		len++;
	if (str[len] != '\0')
		aux = ft_substr(str, len, i - len);
	else
		aux = NULL;
	free(str);
	return (aux);
}
