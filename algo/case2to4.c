/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case2to4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:29:50 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case2(t_control *control, int op)
{
	t_list	*lst;

	lst = control->pile_a;
	if (lst->nb > lst->next->nb)
	{
		ra(control, 1);
		op++;
	}
	return (op);
}

int	case3_next(t_control *control, int op, t_list *lst)
{
	t_list	*a;

	a = lst;
	if (a->spos == 2 && a->next->spos == 0 && a->next->next->spos == 1)
	{
		op++;
		ra(control, 1);
		return (op);
	}
	else if (a->spos == 0 && a->next->spos == 2 && a->next->next->spos == 1)
	{
		op = op + 2;
		rra(control, 1);
		sa(control, 1);
	}
	return (op);
}

int	case3(t_control *control, int op)
{
	t_list	*a;

	a = control->pile_a;
	if (a->nb < a->next->nb && a->next->nb < a->next->next->nb)
		return (op);
	else if (a->spos == 1 && a->next->spos == 0 && a->next->next->spos == 2)
	{
		sa(control, 1);
		op++;
		return (op);
	}
	else if (a->spos == 1 && a->next->spos == 2 && a->next->next->spos == 0)
	{
		rra(control, 1);
		op++;
		return (op);
	}
	else if (a->spos == 2 && a->next->spos == 1 && a->next->next->spos == 0)
	{
		sa(control, 1);
		rra(control, 1);
		op = op + 2;
		return (op);
	}
	return (case3_next(control, op, a));
}

int	case4_next(t_control *control, int op)
{
	t_list	*a;

	a = control->pile_a;
	if (a->spos == 2 && a->next->spos == 3 && a->next->next->spos == 0
		&& a->next->next->next->spos == 1)
	{
		rra(control, 1);
		rra(control, 1);
		op = op + 2;
	}
	else if (a->spos == 3 && a->next->spos == 0 && a->next->next->spos == 1
		&& a->next->next->next->spos == 2)
	{
		ra(control, 1);
		op++;
	}
	else
	{
		op = push0(control, op);
		ft_get_stackpos(control);
		op = case3(control, op);
		pa(control, 1);
		op++;
	}
	return (op);
}

int	case4(t_control *control, int op)
{
	t_list	*a;

	a = control->pile_a;
	if (a->spos == 0 && a->next->spos == 1 && a->next->next->spos == 2
		&& a->next->next->next->spos == 3)
		return (op);
	else if (a->spos == 1 && a->next->spos == 2 && a->next->next->spos == 3
		&& a->next->next->next->spos == 0)
	{
		rra(control, 1);
		op++;
		return (op);
	}
	else
		return (case4_next(control, op));
	return (op);
}
