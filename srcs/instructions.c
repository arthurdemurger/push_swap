/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:04 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/13 18:25:02 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	ft_swap(int *stack, int name, int is_double)
{
	// code

	if (!is_double) // use my ft_printf ?
	{
		write(1, "s", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(int *stack, int name)
{
	// code

	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	ft_rotate(int *stack, int name, int is_double)
{
	// code
	if (!is_double) // use my ft_printf ?
	{
		write(1, "r", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	ft_reverse_rot(int *stack, int name, int is_double)
{
	// code
	if (!is_double) // use my ft_printf ?
	{
		write(1, "rr", 2);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	ft_double(t_stack *stacks, int ins)
{
	if (ins == SWAP)
	{
		ft_swap(stacks, stacks->name_a, DOUBLE);
		ft_swap(stacks, stacks->name_b, DOUBLE);
		write (1, "ss\n", 3);
	}
	else if (ins == ROTATE)
	{
		ft_rotate(stacks, stacks->name_a, DOUBLE);
		ft_rotate(stacks, stacks->name_b, DOUBLE);
		write (1, "rr\n", 3);
	}
	if (ins == REVERSE)
	{
		ft_reverse_rot(stacks, stacks->name_a, DOUBLE);
		ft_reverse_rot(stacks, stacks->name_b, DOUBLE);
		write (1, "rrr\n", 4);
	}
}