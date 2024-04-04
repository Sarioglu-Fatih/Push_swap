/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:54 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push0_next(t_control *control, int op, int up, int down)
{
	if (up <= down)
	{
		while (control->pile_a->spos != 0)
		{
			ra(control, 1);
			op++;
		}
	}
	else
	{
		while (control->pile_a->spos != 0)
		{
			rra(control, 1);
			op++;
		}
	}
	op++;
	pb(control, 1);
	return (op);
}

int	push0(t_control *control, int op)
{
	int		up;
	int		down;
	t_list	*lst;

	up = 0;
	down = 0;
	lst = control->pile_a;
	while (lst->spos != 0)
	{
		lst = lst->next;
		up++;
	}
	while (lst)
	{
		lst = lst->next;
		down++;
	}
	return (push0_next(control, op, up, down));
}

int	ft_lowcase(t_control *control, int op)
{
	if (!control->pile_b)
		return (op);
	else if (ft_struct_numbers_a(control) == 1)
		return (op);
	else if (ft_struct_numbers_a(control) == 2)
	{
		op = case2(control, op);
		return (op);
	}
	else if (ft_struct_numbers_a(control) == 3)
	{
		op = case3(control, op);
		return (op);
	}
	else if (ft_struct_numbers_a(control) == 4)
		op = case4(control, op);
	return (op);
}
