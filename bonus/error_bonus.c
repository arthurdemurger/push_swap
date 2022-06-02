/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:53:17 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 00:28:33 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_error(t_stack *stacks)
{
	if (stacks->a)
		ft_lstclear(&(stacks->a));
	if (stacks->b)
		ft_lstclear(&(stacks->b));
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}
