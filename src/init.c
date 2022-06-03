/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:04:58 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/03 17:45:14 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_arg(t_stack *stacks)
{
	t_list	*tmp;
	t_list	*lst;

	lst = stacks->a;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->data == tmp->data)
				ft_error(stacks);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	transform_stack(t_stack *stacks)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * stacks->size);
	if (!tab)
		ft_error(stacks);
	i = -1;
	while (++i < stacks->size)
	{
		tab[i] = stacks->a->data;
		stacks->a = stacks->a->next;
	}
	while (stacks->a)
	{
		i = 0;
		while (stacks->a->data != tab[i])
			i++;
		stacks->a->nb = i;
		stacks->a = stacks->a->next;
	}
}

void	prev_init(t_list *lst)
{
	lst->prev = NULL;
	while (lst && lst->next)
	{
		(lst->next)->prev = lst;
		lst = lst->next;
	}
}

void	ft_init(t_stack *stacks, char **av)
{
	int		i;

	i = 1;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->name_a = A;
	stacks->name_b = B;
	while (av[++i])
		ft_lstadd_back(&stacks->a, ft_lstnew(ft_atoi(av[i], stacks), stacks));
	/*
	stacks->size = ft_lstsize(stacks->a);
	prev_init(stacks->a);
	check_arg(stacks);
	transform_stack(stacks);
	*/
}
