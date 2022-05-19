/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:06:46 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/19 15:54:09 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

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
	struct s_list	*prev;
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
void	sort(t_stack *stacks);
int		is_in_range(t_list *lst, int start, int end);
int		is_sorted(t_list *lst);
void	smart_rotate(t_stack *stacks, int max, int name);
void	complex_sort(t_stack *stacks);

/*
** Libft functions
*/

int		ft_atoi(const char *str, t_stack *stacks);
int		ft_findindex(t_list *lst, int nb);
int		ft_findmax(t_list *lst);
int		ft_findmin(t_list *lst);
int		ft_findorder(t_list *lst, int nb);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lst_prelast(t_list *lst);
t_list	*ft_lstnew(int content, t_stack *stacks);
int		ft_lstsize(t_list *lst);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(char *s);
char	*ft_substr(char const *s, int start, int len);

#endif