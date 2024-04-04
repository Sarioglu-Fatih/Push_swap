/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closer_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 11:33:45 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_closer6(int (*limit)[2], int size, t_list **temp, t_list *a)
{
	(*limit)[0] = 0;
	(*limit)[1] = size;
	(*temp) = a;
}

void	find_closer7(t_list **b, int (*limit)[2])
{
	(*limit)[0]++;
	(*b) = (*b)->next;
}

void	find_closer8(t_list **a, int (*upord)[2])
{
	while (*a)
	{
		(*a) = (*a)->next;
		(*upord)[1]++;
	}
}
