/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:04 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/03 17:59:50 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list *lst, char stack, int is_double)
{
	int	tmp;

	if (lst && lst->next)
	{
		tmp = lst->nb;
		lst->nb = lst->next->nb;
		lst->next->nb = tmp;
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
	}
	if (!is_double)
		ft_print_ins("s", stack);
}

void	ft_push(t_list **dest, t_list **src, char stack, int do_print)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	else
	{
		tmp = (*src)->next;
		ft_lstadd_front(dest, *src);
		(*src) = tmp;
	}
	if (do_print == PRINT)
		ft_print_ins("p", stack);
}

void	ft_rotate(t_list **lst, char stack, int is_double)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	if (!is_double)
		ft_print_ins("r", stack);
}

void	ft_reverse_rot(t_list **lst, char stack, int is_double)
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	tmp = ft_lst_prelast(*lst);
	ft_lstadd_front(lst, tmp->next);
	tmp->next = NULL;
	if (!is_double)
		ft_print_ins("rr", stack);
}

void	ft_double(t_stack *stacks, int ins)
{
	if (ins == SWAP)
	{
		ft_swap(stacks->a, A, DOUBLE);
		ft_swap(stacks->b, B, DOUBLE);
		write (1, "ss\n", 3);
	}
	else if (ins == ROTATE)
	{
		ft_rotate(&stacks->a, A, DOUBLE);
		ft_rotate(&stacks->b, B, DOUBLE);
		write (1, "rr\n", 3);
	}
	else if (ins == REVERSE)
	{
		ft_reverse_rot(&stacks->a, A, DOUBLE);
		ft_reverse_rot(&stacks->b, B, DOUBLE);
		write (1, "rrr\n", 4);
	}
}
