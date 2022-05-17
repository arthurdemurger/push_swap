/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:53:17 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/17 14:51:39 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack *stacks)
{
	if (stacks->a)
		ft_lstclear(&(stacks->a));
	if (stacks->b)
		ft_lstclear(&(stacks->b));
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}
