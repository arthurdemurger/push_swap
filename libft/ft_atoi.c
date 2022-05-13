/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:28:57 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/13 19:18:40 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	long long	sum;
	int					sign;
	int					i;
	int					size;

	size = 0;
	sum = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && ++size)
		sum = sum * 10 + str[i++] - 48;
	sum *= sign;
	if ((str[i] != '\0' && !ft_isdigit(str[i])))
		ft_error();
	if (size > 10 || sum > 2147483647 || sum < -2147483648)
		ft_error();
	return (sum);
}