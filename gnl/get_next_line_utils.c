/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:09:07 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 16:00:33 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line_break(char *str)
{
	while (str && *str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *src)
{
	char	*str;
	int		i;

	i = -1;
	if (!src)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(src) + 1));
	if (!str)
		return (NULL);
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
	return (str);
}

char	*gnl_strjoin(char *stash, char *buf)
{
	char	*dst;
	int		i;
	int		j;

	if (!stash)
		return (ft_strdup_gnl(buf));
	if (!*buf)
		return (stash);
	dst = malloc(sizeof(char) * (ft_strlen_gnl(stash)
				+ ft_strlen_gnl(buf) + 1));
	if (!dst)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		dst[i] = stash[i];
	while (buf[j])
		dst[i++] = buf[j++];
	dst[i] = 0;
	free(stash);
	return (dst);
}

char	*gnl_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}
