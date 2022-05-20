/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:25:21 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/20 18:43:24 by ademurge         ###   ########.fr       */
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

void	complex_sort2(t_stack *stacks, int med_a, int max)
{
	int	med_b;

	med_b = ft_find_med(stacks->b, ft_lstsize(stacks->b));
	while (ft_lstsize(stacks->b))
	{
		if (stacks->b->nb >= med_b)
		{
			while (stacks->a->nb >= med_b && stacks->a->nb
				&& stacks->a->nb < stacks->b->nb)
				ft_rotate(&stacks->a, A, SIMPLE);
			ft_push(&stacks->a, &stacks->b, A, PRINT);
			while (ft_lstlast(stacks->a)->nb >= med_b)
				ft_reverse_rot(&stacks->a, A, SIMPLE);
		}
		else if (stacks->b->nb < med_b)
		{
			while (ft_lstlast(stacks->a)->nb >= med_a
				&& ft_lstlast(stacks->a)->nb > stacks->b->nb)
				ft_reverse_rot(&stacks->a, A, SIMPLE);
			ft_push(&stacks->a, &stacks->b, A, PRINT);
			while (stacks->a->nb >= med_a && stacks->a->nb < med_b)
				ft_rotate(&stacks->a, A, SIMPLE);
		}
	}
	while (stacks->a->nb >= med_a)
		ft_rotate(&stacks->a, A, SIMPLE);
}

void	complex_sort(t_stack *stacks, int med, int max)
{
	while (is_in_range(stacks->a, med, ft_findmax(stacks->a)))
	{
		if (stacks->a->nb >= med)
			ft_push(&stacks->b, &stacks->a, B, PRINT);
		else if (ft_lstlast(stacks->a)->nb >= med)
		{
			ft_reverse_rot(&stacks->a, A, SIMPLE);
			ft_push(&stacks->b, &stacks->a, B, PRINT);
		}
		else
			ft_rotate(&stacks->a, A, SIMPLE);
	}
	complex_sort2(stacks, med, max);
}

int	nb_bfr_med(t_list *lst, int med)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->nb < med)
			i++;
		lst = lst->next;
	}
	return (i);
}

void	sort_algo(t_stack *stacks)
{
	int	med;
	int	old_med;
	int	max;

	med = ft_find_med(stacks->a, stacks->size);
	complex_sort(stacks, med, ft_findmax(stacks->a));
	while (nb_bfr_med(stacks->a, med) >= 2)
	{
		old_med = med;
		max = nb_bfr_med(stacks->a, med);
		med = ft_find_med(stacks->a, max);
		complex_sort(stacks, med, old_med);
	}
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