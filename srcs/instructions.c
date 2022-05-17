/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:04 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/17 21:49:28 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list *lst, int name, int is_double)
{
	int	tmp;

	if (lst && lst->next)
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
	}
	if (!is_double)
		ft_print_ins("s", name);
}

void	ft_push(t_list **dest, t_list **src)
{
	t_list tmp;

	if (!(*src))
		return ;
	else if (!dest)
	{
		(*dest)->data = (*src)->data;
		(*dest)->next = NULL;
		*src = (*src)->next;
	}
	else
	{
		tmp.data = (*src)->data;
		tmp.next = NULL;
		ft_lstadd_front(dest, &tmp);
		*src = (*src)->next;
	}
}

/*
void	ft_rotate(t_stack *stacks, int name, int is_double)
{
	// code
}

void	ft_reverse_rot(t_stack *stacks, int name, int is_double)
{
	// code
}


void	ft_double(t_stack *stacks, int ins)
{
	if (ins == SWAP)
	{
		ft_swap(stacks->a, stacks->name_a, DOUBLE);
		ft_swap(stacks->a, stacks->name_a, DOUBLE);
		write (1, "ss\n", 3);
	}
	else if (ins == ROTATE)
	{
		ft_rotate(stacks, stacks->name_a, DOUBLE);
		ft_rotate(stacks, stacks->name_b, DOUBLE);
		write (1, "rr\n", 3);
	}
	if (ins == REVERSE)
	{
		ft_reverse_rot(stacks, stacks->name_a, DOUBLE);
		ft_reverse_rot(stacks, stacks->name_b, DOUBLE);
		write (1, "rrr\n", 4);
	}
}
*/