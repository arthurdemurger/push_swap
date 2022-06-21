/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:53:17 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/21 13:13:10 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_error(t_stack *stacks)
{
	free_stacks(stacks);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
