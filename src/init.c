/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:04:58 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 15:28:47 by ademurge         ###   ########.fr       */
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
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stacks->a;
	while (i++ < stacks->size)
	{
		tmp->nb = ft_findorder(stacks->a, tmp->data);
		tmp = tmp->next;
	}
}

void	ft_init(t_stack *stacks, char **av)
{
	int		i;

	i = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->name_a = A;
	stacks->name_b = B;
	while (av[++i])
		ft_lstadd_back(&stacks->a, ft_lstnew(ft_atoi(av[i], stacks), stacks));
	stacks->size = ft_lstsize(stacks->a);
	check_arg(stacks);
	transform_stack(stacks);
}
