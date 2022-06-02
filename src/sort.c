/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:02:56 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 16:02:08 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	ft_push(&stacks->b, &stacks->a, B, PRINT);
	if (!is_sorted(stacks->a))
		sort_3(stacks);
	ft_push(&stacks->a, &stacks->b, A, PRINT);
}

static void	sort_5(t_stack *stacks)
{
	int	index;
	int	min;

	min = ft_findmin(stacks->a);
	index = ft_findindex(stacks->a, min);
	if (index <= 2)
		while (stacks->a->data != min)
			ft_rotate(&stacks->a, A, SIMPLE);
	else if (index >= 3)
		while (stacks->a->data != min)
			ft_reverse_rot(&stacks->a, A, SIMPLE);
	ft_push(&stacks->b, &stacks->a, B, PRINT);
	sort_4(stacks);
	ft_push(&stacks->a, &stacks->b, A, PRINT);
}

void	sort_43(t_stack *stacks)
{
	int	min;
	int	index;

	while (ft_lstsize(stacks->a) > 3)
	{
		min = ft_findmin(stacks->a);
		index = ft_findindex(stacks->a, min);
		while (stacks->a->data != min)
		{
			if (index < 1 + stacks->size / 2)
				ft_rotate(&stacks->a, A, SIMPLE);
			else
				ft_reverse_rot(&stacks->a, A, SIMPLE);
		}
		ft_push(&stacks->b, &stacks->a, B, PRINT);
	}
	if (!is_sorted(stacks->a))
		sort_3(stacks);
	while (stacks->b)
		ft_push(&stacks->a, &stacks->b, A, PRINT);
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
	else if (stacks->size <= 43)
		sort_43(stacks);
	else
		radix_sort(stacks);
}
