/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case3_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:24:18 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case3_b_next(t_control *control, int op)
{
	t_list	*a;

	a = control->pile_a;
	if (a->spos == 2 && a->next->spos == 0 && a->next->next->spos == 1)
	{
		op++;
		ra(control, 1);
	}
	else if (a->spos == 0 && a->next->spos == 2 && a->next->next->spos == 1)
	{
		op = op + 2;
		sa(control, 1);
		ra(control, 1);
	}
	else if (a->spos == 2 && a->next->spos == 1 && a->next->next->spos == 0)
	{
		sa(control, 1);
		rra(control, 1);
		op = op + 2;
	}
	return (op);
}

int	case3_b(t_control *control, int op, t_list *lst)
{
	t_list	*a;

	a = lst;
	if (a->nb < a->next->nb && a->next->nb < a->next->next->nb)
		return (op);
	else if (a->spos == 1 && a->next->spos == 0 && a->next->next->spos == 2)
	{
		sa(control, 1);
		op++;
	}
	else if (a->spos == 1 && a->next->spos == 2 && a->next->next->spos == 0)
	{
		rra(control, 1);
		op++;
	}
	else if (a->spos == 0 && a->next->spos == 1 && a->next->next->spos == 2)
	{
		return (op);
	}
	return (case3_b_next(control, op));
}
