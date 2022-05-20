/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:25:21 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 16:41:02 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack *stacks)
{
	t_list	*tmp;

	while (ft_lstsize(stacks->a))
	{
		tmp = stacks->a;
		while (ft_lstsize(stacks->b) && stacks->b->nb > stacks->a->nb)
			ft_push(&stacks->a, &stacks->b, A, PRINT);
		ft_push(&stacks->b, &stacks->a, B, PRINT);
	}
	while (ft_lstsize(stacks->b))
		ft_push(&stacks->a, &stacks->b, A, PRINT);
}

void	complex_sort(t_stack *stacks)
{
	int	med;

	while (ft_lstsize(stacks->a) > 2)
	{
		med = ft_find_med(stacks->a);
		while (is_in_range(stacks->a, med))
		{
			if (stacks->a->nb < med)
				ft_push(&stacks->b, &stacks->a, B, PRINT);
			else if (ft_lstlast(stacks->a)->nb < med)
			{
				ft_reverse_rot(&stacks->a, A, SIMPLE);
				ft_push(&stacks->b, &stacks->a, B, PRINT);
			}
			else
				ft_rotate(&stacks->a, A, SIMPLE);
		}
	}
	if (!is_sorted(stacks->a))
		ft_swap(stacks->a, A, SIMPLE);
}

/*
int	find_nb_chunks(t_list *lst, int chunk)
{
	int	nb;

	nb = 0;
	while (lst)
	{
		while (lst && lst->chunk == chunk)
		{
			nb++;
			lst = lst->next;
		}
		if (lst)
			lst = lst->chunk;
	}
	return (nb);
}

int	find_med_chunks(t_list *lst, int nb_in_chunk)
{
	int	tab[nb_in_chunk];
	int	i;
	int	tmp;

	tmp = nb_in_chunk;
	i = 0;
	while (nb_in_chunk--)
	{
		tab[i++] = lst->nb;
		lst = lst->next;
	}
	ft_sort_int_tab(tab, tmp);
	return (tab[tmp / 2]);
}

void	use_chunks(t_stack *stacks)
{
	int	med;
	int	nb_in_chunks;

	while (stacks->nb_chunks--)
	{
		nb_in_chunks = find_nb_chunks(stacks->b, stacks->b->chunk);
		med = find_med_chunks(stacks->b, stacks->nb_chunks);
		while ()
		nb_chunks--;
	}

	if (!is_rev_sorted(stacks->b))
		ft_swap(stacks->b, B, SIMPLE);
}

static int	first_occ(t_list *lst, int max)
{
	int	i;

	i = 1;
	while (lst && lst->nb >= max)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	last_occ(t_list *lst, int max)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = ft_lstlast(lst);
	while (tmp && tmp->nb >= max)
	{
		tmp = tmp->prev;
		i++;
	}
	return (i + 1);
}

void	smart_rotate(t_stack *stacks, int max, int name)
{
	int	first;
	int	last;

	first = first_occ(stacks->a, max);
	last = last_occ(stacks->a, max);
	if (first < last)
		while (first--)
			ft_rotate(&stacks->a, name, SIMPLE);
	else
		while (last--)
			ft_reverse_rot(&stacks->a, name, SIMPLE);
}
*/