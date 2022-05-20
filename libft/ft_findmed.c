/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:05 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 15:18:40 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_med(t_list *lst)
{
	int	array[ft_lstsize(lst)];
	int	i;
	int	size;

	size = ft_lstsize(lst);
	i = -1;
	while (lst)
	{
		array[++i] = lst->nb;
		lst = lst->next;
	}
	ft_sort_int_tab(array, size);
	return (array[size / 2]);
}