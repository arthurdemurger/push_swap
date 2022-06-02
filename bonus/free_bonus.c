/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:09:37 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 00:28:37 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	free_stacks(t_stack *stacks)
{
	if (stacks->a)
		ft_lstclear(&stacks->a);
	if (stacks->b)
		ft_lstclear(&stacks->b);
}
