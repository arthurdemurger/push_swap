/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:53:17 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/10 15:20:05 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack *stacks)
{
	free_stacks(stacks);
	write(STDERR_FILENO, "Error\n", 7);
	exit(EXIT_FAILURE);
}
