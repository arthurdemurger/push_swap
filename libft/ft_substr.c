/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:22:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/21 13:17:32 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*src;
	char	*str;
	int		size;

	src = (char *)s;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(src))
		return (ft_strdup(""));
	size = ft_strlen(&src[start]);
	if (size > len)
		size = len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		exit(1);
	ft_strlcpy(str, &src[start], size + 1);
	return (str);
}
