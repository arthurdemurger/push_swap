/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:25:21 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/19 15:55:09 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	first_occ(t_list *lst, int max)
{
	int	i;

	i = 0;
	while (lst && lst->nb > max)
	{
		lst = lst->next;
		i++;
	}
	if (lst)
		return (i);
	else
		return (-1);
}

static int	last_occ(t_list *lst, int max)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = ft_lstlast(lst);
	while (tmp && tmp->nb > max)
	{
		tmp = tmp->prev;
		i++;
	}
	return (i + 1);
}

void	smart_rotate(t_stack *stacks, int max, int name)
{
	int	first;
	int	last;

	first = first_occ(stacks->a, max);
	last = last_occ(stacks->a, max);
	if (first < last)
		while (first-- >= 0)
			ft_rotate(&stacks->a, name, SIMPLE);
	else
		while (last-- >= 0)
			ft_reverse_rot(&stacks->a, name, SIMPLE);
}

/********************** WORK IN PROGRESS *******************************
void	complex_sort(t_stack *stacks)
{
	int	med;
	int	start;

	med = stacks->size;
	start = 1;
	while (ft_lstsize(stacks->a) > 3)
	{
		if (med % 2 == 0)
			med /= 2;
		else
			med = (med / 2) + 1;
		while (is_in_range(stacks->a, start, start + med - 1))
		{
			smart_rotate(stacks, start + med, A);
			ft_push(&stacks->b, &stacks->a, B, PRINT);
		}
		start += med - 1;
	}
}
************************ WORK IN PROGRESS *****************************/
