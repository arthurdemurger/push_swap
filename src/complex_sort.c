/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:02:19 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 16:02:45 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack *stacks)
{
	int	max;
	int	bits;
	int	i;
	int	j;

	max = stacks->size;
	bits = 0;
	i = -1;
	while ((max >> bits))
		bits++;
	while (++i < bits)
	{
		j = -1;
		while (++j < stacks->size)
		{
			if (((stacks->a->nb >> i) & 1) == 1)
				ft_rotate(&stacks->a, A, SIMPLE);
			else
				ft_push(&stacks->b, &stacks->a, B, SIMPLE);
		}
		while (ft_lstsize(stacks->b))
			ft_push(&stacks->a, &stacks->b, A, SIMPLE);
	}
}
