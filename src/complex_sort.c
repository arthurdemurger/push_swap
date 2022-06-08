/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:00:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/08 12:50:35 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

	/*
	**** 1. The stack A must be divided in two by the median number of the stack.
	**** 2. Send all the numbers <= the median number to the stack B, but intelligently,
			until there are <= 3 numbers in the stack. It is necessary to optimize the moves.
	**** 3. Here, we will start to have fun.
			You have to push to A but in the most optimized way possible,
			paying attention to the next pushes you can make, ...
	*/

int	smart_rotate(t_list *lst, int max)
{
	int		top;
	int		bot;
	t_list	*tmp;

	tmp = ft_lstlast(lst);
	top = 0;
	bot = 1;
	while (lst)
	{
		if (lst->data < max)
			break ;
		top++;
		lst = lst->next;
	}
	while (tmp)
	{
		if (tmp->data < max)
			break ;
		bot++;
		tmp = tmp->prev;
	}
	if (top <= bot)
		return (TOP);
	else
		return (BOTTOM);
}

void	split_in_chunks(t_stack *stacks)
{
	int	med;
	int	rot;

	while (ft_lstsize(stacks->a) > 3)
	{
		med = ft_find_med(stacks->a);
		while (is_in_range(stacks->a, med))
		{
			rot = smart_rotate(stacks->a, med);
			if (rot == TOP && stacks->a->data >= med)
				while (stacks->a->data >= med)
					ft_rotate(&stacks->a, A, SIMPLE);
			else if (rot == BOTTOM)
				while (stacks->a->data >= med)
					ft_reverse_rot(&stacks->a, A, SIMPLE);
			ft_push(&stacks->b, &stacks->a, B, PRINT);
		}
	}
	if (!is_sorted(stacks->a))
	{
		if (ft_lstsize(stacks->a) == 3)
			sort_3(stacks);
		else
			ft_swap(stacks->a, A, SIMPLE);
	}
}

void	smart_push(t_stack *stacks)
{
	// code
}
