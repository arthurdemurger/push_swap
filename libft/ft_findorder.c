/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:09:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 15:02:01 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_findorder(t_list *lst, int nb)
{
	int	ord;

	ord = 1;
	while (lst)
	{
		if (nb > lst->nb)
			ord++;
		lst = lst->next;
	}
	return (ord);
}
