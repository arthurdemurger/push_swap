/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:37:27 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/19 15:55:46 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->nb > (lst->next)->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_in_range(t_list *lst, int start, int end)
{
	while (lst)
	{
		if (lst->nb >= start && lst->nb <= end)
			return (1);
		lst = lst->next;
	}
	return (0);
}
