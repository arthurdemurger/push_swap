/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:02:56 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/18 18:35:21 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > (lst->next)->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	sort_3(t_stack *stacks)
{
	if (stacks->a->data > stacks->a->next->data
		&& (stacks->a->next)->data < ((stacks->a->next)->next)->data)
	{
		if (stacks->a->data < ((stacks->a->next)->next)->data)
			ft_swap(stacks->a, A, SIMPLE);
		else
			ft_rotate(&stacks->a, A, SIMPLE);
	}
	else if (stacks->a->data < (stacks->a->next)->data)
	{
		ft_reverse_rot(&stacks->a, A, SIMPLE);
		if (!is_sorted(stacks->a))
			ft_swap(stacks->a, A, SIMPLE);
	}
	else
	{
		ft_swap(stacks->a, A, SIMPLE);
		ft_reverse_rot(&stacks->a, A, SIMPLE);
	}
}

static void	sort_4(t_stack *stacks)
{
	int	index;
	int	min;

	min = ft_findmin(stacks->a);
	index = ft_findindex(stacks->a, min);
	if (index == 1)
		while (stacks->a->data != min)
			ft_rotate(&stacks->a, A, SIMPLE);
	else if (index == 2 || index == 3)
		while (stacks->a->data != min)
			ft_reverse_rot(&stacks->a, A, SIMPLE);
	ft_push(&stacks->b, &stacks->a, B);
	if (!is_sorted(stacks->a))
		sort_3(stacks);
	ft_push(&stacks->a, &stacks->b, A);
}

static void	sort_5(t_stack *stacks)
{
	int	index;
	int	min;

	while (ft_lstsize(stacks->b) != 2)
	{
		min = ft_findmin(stacks->a);
		index = ft_findindex(stacks->a, min);
		if (index <= 2)
			while (stacks->a->data != min)
				ft_rotate(&stacks->a, A, SIMPLE);
		else if (index <= 4)
			while (stacks->a->data != min)
				ft_reverse_rot(&stacks->a, A, SIMPLE);
		ft_push(&stacks->b, &stacks->a, B);
	}
	sort_3(stacks);
	ft_push(&stacks->a, &stacks->b, A);
	ft_push(&stacks->a, &stacks->b, A);
}

void	sort(t_stack *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	else if (stacks->size == 2)
		ft_swap(stacks->a, A, SIMPLE);
	else if (stacks->size == 3)
		sort_3(stacks);
	else if (stacks->size == 4)
		sort_4(stacks);
	else if (stacks->size == 5)
		sort_5(stacks);
	//else
		//code
}