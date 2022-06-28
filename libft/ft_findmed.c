/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:26:21 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/29 00:59:30 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_med(t_list *lst, t_stack *stacks)
{
	int	*array;
	int	i;
	int	size;

	size = ft_lstsize(lst);
	array = malloc(sizeof(int) * size);
	if (!array)
		ft_error(stacks, MALLOC);
	i = -1;
	while (lst)
	{
		array[++i] = lst->data;
		lst = lst->next;
	}
	ft_sort_int_tab(array, size);
	i = array[size / 2];
	free(array);
	return (i);
}
