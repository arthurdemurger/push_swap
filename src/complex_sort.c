/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:00:08 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/03 01:09:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	split_in_chunks(t_stack *stacks)
{
	/*
	**** 1. The stack A must be divided in two by the median number of the stack.
	**** 2. Send all the numbers <= the median number to the stack B, but intelligently,
			until there are <= 3 numbers in the stack. It is necessary to optimize the moves.
	**** 3. Here, we will start to have fun.
			You have to push to A but in the most optimized way possible,
			paying attention to the next pushes you can make, ...
	*/
}
