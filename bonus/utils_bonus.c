/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:37:27 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/02 00:46:15 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > (lst->next)->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_rev_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->nb < (lst->next)->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_in_range(t_list *lst, int min, int max)
{
	while (lst)
	{
		if (lst->nb >= min && lst->nb <= max)
			return (1);
		lst = lst->next;
	}
	return (0);
}
