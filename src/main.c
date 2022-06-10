/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:59 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/31 00:45:13 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	char	**split;

	if (argc > 1)
	{
		if (argc == 2)
		{
			split = ft_split(argv[1], ' ');
			ft_init(&stacks, split);
			free(split);
		}
		else
			ft_init(&stacks, argv);
		sort(&stacks);
		free_stacks(&stacks);
	}
	return (0);
}
