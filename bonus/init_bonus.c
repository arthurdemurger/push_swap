/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:04:58 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/21 13:16:28 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	check_arg(t_stack *stacks)
{
	t_list	*tmp;
	int		*tab;
	int		i;
	int		j;

	i = 0;
	tab = malloc(sizeof(int) * (stacks->size + 1));
	if (!tab)
		exit(1);
	tmp = stacks->a;
	while (tmp)
	{
		tab[i++] = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	while (i < stacks->size)
	{
		j = i + 1;
		while (j < stacks->size)
			if (tab[i] == tab[j++])
				ft_error(stacks);
		i++;
	}
	free(tab);
}

void	ft_init(t_stack *stacks, char **av)
{
	int		i;
	t_list	*tmp;

	i = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	while (av[++i])
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			exit(1);
		tmp->data = ft_atoi(av[i], stacks);
		tmp->next = NULL;
		ft_lstadd_back(&stacks->a, tmp);
	}
	stacks->size = ft_lstsize(stacks->a);
	check_arg(stacks);
}
