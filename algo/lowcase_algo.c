/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowcase_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:30:38 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lowcase_algo2(t_list **a, t_list **b, int (*upord)[2])
{
	while ((*a)->next->next && !((*b)->pos > (*a)->pos && (*b)->pos
			< (*a)->next->pos))
	{
		(*a) = (*a)->next;
		(*upord)[0]++;
	}
}

void	lowcase_algo3(t_list **a, int (*upord)[2])
{
	(*upord)[0]++;
	(*a) = (*a)->next;
}

void	lowcase_algo4(t_list **a, int (*upord)[2], t_list *temp)
{
	(*a) = temp;
	(*upord)[0] = 0;
	while ((*a)->pos < (*a)->next->pos && (*a)->next->next)
	{
		(*upord)[0]++;
		(*a) = (*a)->next;
	}
	if ((*a)->pos < (*a)->next->pos)
	{
		(*upord)[0]++;
		(*a) = (*a)->next;
	}
	if ((*a)->next)
	{
		if ((*a)->pos > (*a)->next->pos)
		{
			(*upord)[0]++;
			(*a) = (*a)->next;
		}
	}
	else
		(*upord)[0] = 0;
}

void	lowcase_algo5(t_list **a, int (*upord)[2], t_control *control, int *op)
{
	while (*a)
	{
		(*upord)[1]++;
		(*a) = (*a)->next;
	}
	if ((*upord)[1] < 1)
		(*upord)[0] = 0;
	while ((*upord)[1] < (*upord)[0] && (*upord)[1] > 0)
	{
		rra(control, 1);
		(*op)++;
		(*upord)[1]--;
	}
	while ((*upord)[0] <= (*upord)[1] && (*upord)[0] > 0)
	{
		ra(control, 1);
		op++;
		(*upord)[0]--;
	}
}

int	lowcase_algo(t_control *control, int op)
{
	int		upord[2];
	t_list	*a;
	t_list	*b;
	t_list	*temp;

	upord[0] = 0;
	upord[1] = 0;
	a = control->pile_a;
	b = control->pile_b;
	temp = control->pile_a;
	lowcase_algo2(&a, &b, &upord);
	if (b->pos > a->pos && b->pos < a->next->pos)
		lowcase_algo3(&a, &upord);
	else if (b->pos > a->next->pos && b->pos < temp->pos)
		upord[0] = 0;
	else if (!(b->pos > a->pos && b->pos < a->next->pos))
		lowcase_algo4(&a, &upord, temp);
	lowcase_algo5(&a, &upord, control, &op);
	pa(control, 1);
	op++;
	return (op);
}
