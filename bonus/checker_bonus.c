/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:53:29 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 16:09:43 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	do_cmd(char	*cmd, t_stack *stacks)
{
	if (!ft_strcmp(cmd, "sa\n"))
		ft_swap(stacks->a);
	else if (!ft_strcmp(cmd, "sb\n"))
		ft_swap(stacks->b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ft_double(stacks, SWAP);
	else if (!ft_strcmp(cmd, "pa\n"))
		ft_push(&stacks->a, &stacks->b);
	else if (!ft_strcmp(cmd, "pb\n"))
		ft_push(&stacks->b, &stacks->a);
	else if (!ft_strcmp(cmd, "ra\n"))
		ft_rotate(&stacks->a);
	else if (!ft_strcmp(cmd, "rb\n"))
		ft_rotate(&stacks->b);
	else if (!ft_strcmp(cmd, "rr\n"))
		ft_double(stacks, ROTATE);
	else if (!ft_strcmp(cmd, "rra\n"))
		ft_reverse_rot(&stacks->a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		ft_reverse_rot(&stacks->b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		ft_double(stacks, REVERSE);
	else
		return (CMD_ERROR);
	return (1);
}

void	read_cmd(t_stack *stacks)
{
	char	*cmd;

	cmd = "42";
	while (cmd)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (cmd)
		{
			if (do_cmd(cmd, stacks) == CMD_ERROR)
				ft_error(stacks);
			free(cmd);
		}
	}
}

int	main(int argc, char **argv)
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
