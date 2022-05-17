/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:06:46 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/17 21:04:43 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

/*
** Libraries
*/

# include <stdio.h> // TO DELETE
# include <unistd.h>
# include <stdlib.h>

/*
** Structures
*/

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}	t_list;

typedef struct s_stack
{
	char	name_a;
	char	name_b;
	t_list	*a;
	t_list	*b;
}	t_stack;

/*
** Define constants
*/

# define SWAP 1
# define ROTATE 2
# define REVERSE 3
# define DOUBLE 1
# define SIMPLE 0

void	print_stacks(t_stack *stacks); // TO DELETE

/*
** Main functions
*/

void	ft_error(t_stack *stacks);
void	ft_init(t_stack *stacks, char **av);
void	ft_swap(t_list *lst, int name, int is_double);
void	ft_print_ins(char *s, char name);
void	ft_double(t_stack *stacks, int ins);
void	ft_push(t_list **dest, t_list **src);

/*
** Libft functions
*/

int		ft_atoi(const char *str, t_stack *stacks);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content, t_stack *stacks);
int		ft_lstsize(t_list *lst);
int		ft_strlen(char *s);

#endif