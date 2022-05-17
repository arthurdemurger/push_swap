/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:59 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/17 21:43:55 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	t_list lst2;
	t_list lst1;

	lst1.data = 4;
	lst2.data = 42;
	lst1.next = &lst2;
	lst2.next = NULL;
	if (argc > 1)
	{
		ft_init(&stacks, argv);
		stacks.b = &lst1;
		//ft_push(&stacks.b, &stacks.a);
		//ft_push(&stacks.b, &stacks.a);
		ft_push(&stacks.a, &stacks.b);
		ft_push(&stacks.a, &stacks.b);
		print_stacks(&stacks);
	}
	else
		exit(1);
	return (0);
}
