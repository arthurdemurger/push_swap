/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:04 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 15:40:44 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_swap(t_list *lst)
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
}

void	ft_push(t_list **dest, t_list **src)
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
}

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ft_reverse_rot(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	tmp = ft_lst_prelast(*lst);
	ft_lstadd_front(lst, tmp->next);
	tmp->next = NULL;
}

void	ft_double(t_stack *stacks, int ins)
{
	if (ins == SWAP)
	{
		ft_swap(stacks->a);
		ft_swap(stacks->b);
	}
	else if (ins == ROTATE)
	{
		ft_rotate(&stacks->a);
		ft_rotate(&stacks->b);
	}
	else if (ins == REVERSE)
	{
		ft_reverse_rot(&stacks->a);
		ft_reverse_rot(&stacks->b);
	}
}
