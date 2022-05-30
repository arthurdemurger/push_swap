/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:55:41 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/31 01:11:51 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstnew(int content, t_stack *stacks)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list *));
	if (!lst)
		ft_error(stacks);
	lst->data = content;
	lst->next = NULL;
	return (lst);
}
