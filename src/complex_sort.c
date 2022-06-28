/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:00:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/29 01:00:07 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

	/*
	**** 1. The stack A must be divided in chunks
	**** 2. Send all the numbers <= the max number of the chunk to the stack B,
			but efficiently, until there are <= 5 numbers in the stack.
			It is necessary to optimize the moves.
	**** 3. Here, we will start to have fun.
			You have to push to A but in the most optimized way possible,
			paying attention to the next pushes you can make, ...
	*/

void	smart_push(t_stack *stacks)
{
	if (stacks->a->data < stacks->b->data)
	{
		if ((stacks->a->next)->data > stacks->b->data)
		{
			ft_push(&stacks->a, &stacks->b, A, PRINT);
			ft_swap(stacks->a, A, SIMPLE);
		}
		else
		{
			while (stacks->a->data < stacks->b->data)
				ft_rotate(&stacks->a, A, SIMPLE);
			ft_push(&stacks->a, &stacks->b, A, PRINT);
		}
	}
	else if (stacks->a->data > ft_lstlast(stacks->a)->data)
	{
		while (stacks->a->data > ft_lstlast(stacks->a)->data
			&& ft_lstlast(stacks->a)->data > stacks->b->data)
			ft_reverse_rot(&stacks->a, A, SIMPLE);
		ft_push(&stacks->a, &stacks->b, A, PRINT);
	}
	else
		ft_push(&stacks->a, &stacks->b, A, PRINT);
}

void	push_split(t_stack *stacks)
{
	while (ft_lstsize(stacks->b) > 1)
	{
		while (stacks->b->data < (stacks->b->next)->data
			&& (stacks->b->next)->data > ft_lstlast(stacks->b)->data)
		{
			if (stacks->a->data < (stacks->b->next)->data)
				ft_double(stacks, ROTATE);
			else
				ft_rotate(&stacks->b, B, SIMPLE);
		}
		if (stacks->b->data < (stacks->b->next)->data
			&& (stacks->b->next)->data < ft_lstlast(stacks->b)->data)
			ft_reverse_rot(&stacks->b, B, SIMPLE);
		while (stacks->b->data > (stacks->b->next)->data
			&& stacks->b->data < ft_lstlast(stacks->b)->data)
			push_split2(stacks);
		smart_push(stacks);
	}
	smart_push(stacks);
}

void	split_big_chunk(t_stack *stacks, int chunk)
{
	int	med;

	med = 0;
	while (ft_lstsize(stacks->a) > 5)
	{
		med += chunk;
		while (is_in_range(stacks->a, med, NB))
		{
			if (stacks->a->nb < med)
				ft_push(&stacks->b, &stacks->a, B, PRINT);
			else
				ft_rotate(&stacks->a, A, SIMPLE);
		}
	}
}

void	split_little_chunk(t_stack *stacks)
{
	int	med;

	while (ft_lstsize(stacks->a) > 5)
	{
		med = ft_find_med(stacks->a, stacks);
		while (is_in_range(stacks->a, med, DATA))
		{
			if (stacks->a->data < med)
				ft_push(&stacks->b, &stacks->a, B, PRINT);
			else
				ft_rotate(&stacks->a, A, SIMPLE);
		}
	}
}

void	complex_sort(t_stack *stacks)
{
	int	chunk;
	int	size;

	chunk = find_chunk(stacks);
	if (stacks->size >= 100 && chunk < stacks->size)
		split_big_chunk(stacks, chunk);
	else
		split_little_chunk(stacks);
	if (!is_sorted(stacks->a))
	{
		size = ft_lstsize(stacks->a);
		if (size == 2)
			ft_swap(stacks->a, A, SIMPLE);
		else if (size == 3)
			sort_3(stacks);
		else if (size == 4)
			sort_4(stacks);
		else if (size == 5)
			sort_5(stacks);
	}
	push_split(stacks);
}
