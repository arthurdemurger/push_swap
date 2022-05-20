/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_med.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:05 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 18:34:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_med(t_list *lst, int max)
{
	int	array[max];
	int	i;
	int	size;

	size = ft_lstsize(lst);
	i = -1;
	while (max--)
		array[++i] = lst->nb;
	ft_sort_int_tab(array, size);
	return (array[size / 2]);
}