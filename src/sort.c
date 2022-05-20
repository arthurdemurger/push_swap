/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:02:56 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 18:01:56 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_3(t_stack *stacks)
{
	if (stacks->a->nb > stacks->a->next->nb
		&& (stacks->a->next)->nb < ((stacks->a->next)->next)->nb)
	{
		if (stacks->a->nb < ((stacks->a->next)->next)->nb)
			ft_swap(stacks->a, A, SIMPLE);
		else
			ft_rotate(&stacks->a, A, SIMPLE);
	}
	else if (stacks->a->nb < (stacks->a->next)->nb)
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
		while (stacks->a->nb != min)
			ft_rotate(&stacks->a, A, SIMPLE);
	else if (index == 2 || index == 3)
		while (stacks->a->nb != min)
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

	while (ft_lstsize(stacks->b) != 2)
	{
		min = ft_findmin(stacks->a);
		index = ft_findindex(stacks->a, min);
		if (index <= 2)
			while (stacks->a->nb != min)
				ft_rotate(&stacks->a, A, SIMPLE);
		else if (index <= 4)
			while (stacks->a->nb != min)
				ft_reverse_rot(&stacks->a, A, SIMPLE);
		ft_push(&stacks->b, &stacks->a, B, PRINT);
	}
	if (!is_sorted(stacks->a))
		sort_3(stacks);
	ft_push(&stacks->a, &stacks->b, A, PRINT);
	ft_push(&stacks->a, &stacks->b, A, PRINT);
}

/*
void	sort_100(t_stack *stacks) // WORK IN PROGRESS
{
	int	i;
	int	chunks;

	i = 1;
	chunks = 3;
	//while (is_in_range(stacks->a, i, (stacks->size / 2) * i))
	while (chunks)
	{
		if ()
		chunks--;
	}
}
*/

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
	else
		sort_algo(stacks);
}

/*
void	sort_large_nb(t_stack *stacks)
{
	int	min;
	int	index;

	while (stacks->a)
	{
		min = ft_findmin(stacks->a);
		index = ft_findindex(stacks->a, min);
		while (stacks->a->nb != min)
		{
			if (index < 1 + stacks->size / 2)
				ft_rotate(&stacks->a, A, SIMPLE);
			else
				ft_reverse_rot(&stacks->a, A, SIMPLE);
		}
		ft_push(&stacks->b, &stacks->a, B, PRINT);
	}
	while (stacks->b)
		ft_push(&stacks->a, &stacks->b, A, PRINT);
}
*/