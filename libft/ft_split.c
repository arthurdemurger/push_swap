/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:28 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/29 01:01:27 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ft_free(int index, char **split)
{
	while (--index)
		free(split[index]);
	free(split);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int		i;
	int		count;
	char	*str;

	str = (char *)s;
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*find_next_word(char *s, char c, int index, t_stack *stacks)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (index)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			index--;
		while (index && s[i] && s[i] != c)
			i++;
	}
	j = i;
	while (s[j] && s[j] != c)
	{
		count++;
		j++;
	}
	return (ft_substr(&s[i], 0, count, stacks));
}

char	**ft_split(char const *s, char c, t_stack *stacks)
{
	char	**str;
	int		i;
	int		count;

	i = -1;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 2));
	if (!str)
		ft_error(stacks, MALLOC);
	str[0] = NULL;
	while (++i < count)
	{
		str[i + 1] = find_next_word((char *)s, c, i + 1, stacks);
		if (!str[i + 1])
			return (ft_free(i + 1, str));
	}
	str[i + 1] = 0;
	return (str);
}
