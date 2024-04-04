/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case5to10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:30:03 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case5to10(t_control *control, int op, int size)
{
	if (size == 5)
	{
		if (control->pile_a->pos > control->pile_a->next->pos)
		{
			sa(control, 1);
			op++;
		}
		while (control->pile_a->next->next->next)
		{
			pb(control, 1);
			op++;
		}
		ft_get_stackpos(control);
		op = case3(control, op);
		ft_get_stackpos(control);
		while (control->pile_b)
			op = lowcase_algo(control, op);
	}
	return (op);
}
