/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:04:58 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/08 18:31:37 by ademurge         ###   ########.fr       */
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

	i = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	printf("%s\n", av[i]);
	while (av[++i])
		ft_lstadd_back(&stacks->a, ft_lstnew(ft_atoi(av[i], stacks), stacks));
	stacks->size = ft_lstsize(stacks->a);
	check_arg(stacks);
}
