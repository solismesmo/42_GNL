/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livieira <livieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:44:18 by livieira          #+#    #+#             */
/*   Updated: 2023/08/29 03:03:56 by livieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		join[i + len_s1] = s2[i];
	join[len_s1 + len_s2] = '\0';
	return (join);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		count++;
		s++;
	}	
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			len_sub;

	i = 0;
	str = "";
	if (!s)
		return (NULL);
	len_sub = ft_strlen(s);
	if (start >= len_sub)
		return (str);
	if (len_sub - start < len)
		len = len_sub - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i] && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
