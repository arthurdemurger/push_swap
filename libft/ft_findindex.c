/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:39:23 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/31 00:55:06 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_findindex(t_list *lst, int nb)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst->data == nb)
			return (index);
		index++;
		lst = lst->next;
	}
	return (-1);
}
