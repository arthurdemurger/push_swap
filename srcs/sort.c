/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:02:56 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/18 17:29:12 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > (lst->next)->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	sort_3(t_stack *stacks)
{
	if (stacks->a->data > stacks->a->next->data
		&& (stacks->a->next)->data < ((stacks->a->next)->next)->data)
	{
		if (stacks->a->data < ((stacks->a->next)->next)->data)
			ft_swap(stacks->a, A, SIMPLE);
		else
			ft_rotate(&stacks->a, A, SIMPLE);
	}
	else if (stacks->a->data < (stacks->a->next)->data)
	{
		ft_reverse_rot(&stacks->a, A, SIMPLE);
		if (!is_sorted(stacks->a))
			ft_swap(stacks->a, A, SIMPLE);
	}
	else
	{
		ft_swap(stacks->a, A, SIMPLE);
		ft_reverse_rot(&stacks->a, A, SIMPLE);
	}
}

//static void	sort_4(t_stack *stacks)
//{
//	//code
//}

//static void	sort_5(t_stack *stacks)
//{
//	//code
//}

void	sort(t_stack *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	else if (stacks->size == 2)
		ft_swap(stacks->a, A, SIMPLE);
	else if (stacks->size == 3)
		sort_3(stacks);
	//else if (stacks->size == 4)
	//	sort_4(stacks);
	//else if (stacks->size == 5)
	//	sort_5(stacks);
	//else
		//code
}