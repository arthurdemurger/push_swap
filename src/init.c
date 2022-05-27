/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:04:58 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/27 13:21:56 by ademurge         ###   ########.fr       */
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
			if (lst->nb == tmp->nb)
				ft_error(stacks);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	transform_stack(t_stack *stacks)
{
	int	i;
	int	array[stacks->size];

	i = -1;
	while (++i < stacks->size)
	{
		array[i] = stacks->data;
		stacks = stacks->next;
	}
	ft_sort_int_tab(array, stacks->size);
	i = -1;
	while (++i < stacks->size)
	{
		stacks->nb = i;
		stacks = stacks->next;
	}
}

void	two_way_init(t_list *lst)
{
	t_list	*tmp;

	lst->prev = NULL;
	while (lst && lst->next)
	{
		tmp = lst;
		lst = lst->next;
		lst->prev = tmp;
	}
}

void	ft_init(t_stack *stacks, char **av)
{
	int		i;

	i = 0;
	stacks->b = NULL;
	stacks->name_a = 'a';
	stacks->name_b = 'b';
	stacks->nb_chunks = 0;
	while (av[++i])
		ft_lstadd_back(&stacks->a, ft_lstnew(ft_atoi(av[i], stacks), stacks));
	two_way_init(stacks->a);
	stacks->size = ft_lstsize(stacks->a);
	check_arg(stacks);
	transform_stack(stacks);
}
