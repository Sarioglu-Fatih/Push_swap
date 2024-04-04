/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:25:04 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_stackpos_b_next(t_control *control, int snb, int pos)
{
	int		temp;
	t_list	*lst;

	lst = control->pile_b;
	while (lst && pos < snb)
	{
		lst = control->pile_b;
		temp = 2147483647;
		while (lst)
		{
			if (lst->spos == -1 && lst->nb < temp)
				temp = lst->nb;
			lst = lst->next;
		}
		lst = control->pile_b;
		while (lst && temp != lst->nb)
			lst = lst->next;
		lst->spos = pos;
		pos++;
	}
}

void	ft_get_stackpos_b(t_control *control)
{
	int		snb;
	int		pos;
	t_list	*lst;

	lst = control->pile_b;
	while (lst)
	{
		lst->spos = -1;
		lst = lst->next;
	}
	pos = 0;
	snb = ft_struct_numbers_b(control);
	ft_get_stackpos_b_next(control, snb, pos);
}

void	ft_get_stackpos_next(t_control *control, int snb, int pos)
{
	int		temp;
	t_list	*lst;

	lst = control->pile_a;
	while (lst && pos < snb)
	{
		lst = control->pile_a;
		temp = 2147483647;
		while (lst)
		{
			if (lst->spos == -1 && lst->nb < temp)
				temp = lst->nb;
			lst = lst->next;
		}
		lst = control->pile_a;
		while (lst && temp != lst->nb)
			lst = lst->next;
		lst->spos = pos;
		pos++;
	}
	ft_get_stackpos_b(control);
}

void	ft_get_stackpos(t_control *control)
{
	int		snb;
	int		pos;
	t_list	*lst;

	lst = control->pile_a;
	while (lst)
	{
		lst->spos = -1;
		lst = lst->next;
	}
	pos = 0;
	snb = ft_struct_numbers_a(control);
	ft_get_stackpos_next(control, snb, pos);
}
