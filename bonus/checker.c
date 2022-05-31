/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:53:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/01 00:28:57 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	read_cmd(char **cmd)
{
	// code
}

int main (int argc, char **argv)
{
	t_stack	stacks;
	char	**cmd;
	char	*tmp;

	if (argc > 1)
	{
		if (argc == 2)
			ft_init(&stacks, ft_split(argv[1], ' '));
		else
			ft_init(&stacks, argv);
		read_cmd(cmd);
	}
	return (0);
}