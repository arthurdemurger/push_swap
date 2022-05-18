/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:59 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/18 22:44:11 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc > 1)
	{
		if (argc == 2)
			ft_init(&stacks, ft_split(argv[1], ' '));
		else
			ft_init(&stacks, argv);
		sort(&stacks);
		print_stacks(&stacks);
	}
	return (0);
}
