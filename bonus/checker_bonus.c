/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:53:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 00:45:20 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	do_cmd(char	*cmd, t_stack *stacks)
{
	if (!ft_strcmp(cmd, "sa"))
		ft_swap(stacks->a, A, SIMPLE);
	else if (!ft_strcmp(cmd, "sb"))
		ft_swap(stacks->b, B, SIMPLE);
	else if (!ft_strcmp(cmd, "ss"))
		ft_double(stacks, SWAP);
	else if (!ft_strcmp(cmd, "pa"))
		ft_push(&stacks->a, &stacks->b, A, PRINT);
	else if (!ft_strcmp(cmd, "pb"))
		ft_push(&stacks->b, &stacks->a, B, PRINT);
	else if (!ft_strcmp(cmd, "ra"))
		ft_rotate(&stacks->a, A, SIMPLE);
	else if (!ft_strcmp(cmd, "rb"))
		ft_rotate(&stacks->b, B, SIMPLE);
	else if (!ft_strcmp(cmd, "rr"))
		ft_double(stacks, ROTATE);
	else if (!ft_strcmp(cmd, "rra"))
		ft_reverse_rot(&stacks->a, A, SIMPLE);
	else if (!ft_strcmp(cmd, "rrb"))
		ft_reverse_rot(&stacks->b, B, SIMPLE);
	else if (!ft_strcmp(cmd, "rrr"))
		ft_double(stacks, REVERSE);
	else
		ft_error(stacks);
}

void	read_cmd(t_stack *stacks)
{
	char	*cmd;

	cmd = "42";
	while (cmd)
	{
		cmd = get_next_line(STDIN);
		if (cmd)
		{
			do_cmd(cmd, stacks);
			free(cmd);
		}
	}
}

int main (int argc, char **argv)
{
	t_stack	stacks;

	if (argc > 1)
	{
		if (argc == 2)
			ft_init(&stacks, ft_split(argv[1], ' '));
		else
			ft_init(&stacks, argv);
		read_cmd(&stacks);
		if (is_sorted(stacks.a))
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
	return (0);
}