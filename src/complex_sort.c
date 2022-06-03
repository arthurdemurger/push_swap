/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:00:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/03 09:43:36 by ademurge         ###   ########.fr       */
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

void	split_in_chunks(t_stack *stacks)
{
	int	size;
	int	med;

	size = stacks->size;
	while (ft_lstsize(stacks->a) > 3)
	{
		med = ft_find_med(stacks->a);
		while (is_in_range(stacks->a, med))
		{
			//push b the numbers < med BUT efficiently
		}
	}
}

void	smart_push(t_stack *stacks)
{
	// code
}
