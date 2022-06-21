/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:09:37 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/21 18:48:43 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

/*
**	Libraries
*/

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Define constants
*/

# define BUFFER_SIZE 42
/*
**	Utils functions
*/

int		is_line_break(char *str);
int		ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *src);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char const *s, int start, int len);

/*
** get_next_line function
*/

char	*get_next_line(int fd);

#endif
