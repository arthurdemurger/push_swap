/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:24:20 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 00:26:30 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_BONUS_H

# define CHECKER_BONUS_H

/*
** Libraries
*/

# include <stdio.h> // TO DELETE !!!!!!!!!!!!!!!!!!
# include <unistd.h>
# include <stdlib.h>

/*
** Structures
*/

typedef struct s_list
{
	struct s_list	*next;
	int				data;
	int				nb;
}	t_list;

typedef struct s_stack
{
	char	name_a;
	char	name_b;
	t_list	*a;
	t_list	*b;
	int		size;
}	t_stack;

/*
** Define constants
*/

# define STDIN 1
# define SWAP 1
# define ROTATE 2
# define REVERSE 3
# define DOUBLE 1
# define SIMPLE 0
# define PRINT 0
# define NO_PRINT 1
# define A 'a'
# define B 'b'

/*
** Main functions
*/

void	print_stacks(t_stack *stacks); // TO DELETE !!!!!!!!!!!!!!!!!!!!
void	ft_error(t_stack *stacks);
void	ft_init(t_stack *stacks, char **av);
void	ft_swap(t_list *lst, char stack, int is_double);
void	ft_print_ins(char *s, char stack);
void	ft_double(t_stack *stacks, int ins);
void	ft_push(t_list **dest, t_list **src, char stack, int do_print);
void	ft_rotate(t_list **lst, char stack, int is_double);
void	ft_reverse_rot(t_list **lst, char stack, int is_double);
int		is_in_range(t_list *lst, int min, int max);
int		is_sorted(t_list *lst);
void	free_stacks(t_stack *stacks);

/*
** Libft functions
*/

int		ft_atoi(const char *str, t_stack *stacks);
int		ft_findindex(t_list *lst, int nb);
int		ft_findmin(t_list *lst);
int		ft_findorder(t_list *lst, int nb);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lst_prelast(t_list *lst);
t_list	*ft_lstnew(int data, t_stack *stacks);
int		ft_lstsize(t_list *lst);
void	ft_sort_int_tab(int *tab, int size);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(char *s);
char	*ft_substr(char const *s, int start, int len);

/*
** GNL functions
*/

char	*get_next_line(int fd);

#endif