/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:06:46 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/13 19:01:40 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

/*
** Libraries
*/

# include <stdio.h> // TO DELETE
# include <unistd.h>
# include <stdlib.h>

/*
** Structure
*/

typedef struct s_stack
{
	int		len;
	char	name_a;
	char	name_b;
	int		*a;
	int		*b;
}	t_stack;

/*
** Define constants
*/

# define SWAP 1
# define ROTATE 2
# define REVERSE 3
# define DOUBLE 1
# define SIMPLE 0

/*
** Main functions
*/

void ft_error(void);
void	ft_init(t_stack *stacks, int ac, char **av);

/*
** Libft functions
*/

int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif