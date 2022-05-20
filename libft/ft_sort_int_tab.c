/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:08:51 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 15:09:10 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		x;
	int		j;

	i = 1;
	while (i < size)
	{
		x = *(tab + i);
		j = i;
		while (j > 0 && *(tab + j - 1) > x)
		{
			*(tab + j) = *(tab + j - 1);
			j -= 1;
		}
		*(tab + j) = x;
		i++;
	}
}
