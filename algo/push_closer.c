/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_closer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:29:12 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_closer2(t_control *control, t_list **a, t_list **b, int *finder)
{
	(*a) = control->pile_a;
	(*b) = control->pile_b;
	if (finder[2] == -1)
		finder[0] = finder[0] * -1;
	if (finder[3] == -1)
		finder[1] = finder[1] * -1;
}

void	push_closer3(t_control *control, int *finder, int *op)
{
	while (finder[1] > 0 && finder[0] > 0)
	{
		rr(control, 1);
		finder[0]--;
		finder[1]--;
		(*op)++;
	}
	while (finder[1] < 0 && finder[0] < 0)
	{
		rrr(control, 1);
		finder[0]++;
		finder[1]++;
		(*op)++;
	}
	while (finder[0] > 0)
	{
		ra(control, 1);
		finder[0]--;
		(*op)++;
	}
}

void	push_closer4(t_control *control, int *finder, int *op)
{
	while (finder[0] < 0)
	{
		rra(control, 1);
		finder[0]++;
		(*op)++;
	}
	while (finder[1] > 0)
	{
		rb(control, 1);
		finder[1]--;
		(*op)++;
	}
	while (finder[1] < 0)
	{
		rrb(control, 1);
		finder[1]++;
		(*op)++;
	}
}

int	push_closer(t_control *control, int *finder, int op)
{
	t_list	*a;
	t_list	*b;

	push_closer2(control, &a, &b, finder);
	push_closer3(control, finder, &op);
	push_closer4(control, finder, &op);
	pa(control, 1);
	op++;
	return (op);
}
