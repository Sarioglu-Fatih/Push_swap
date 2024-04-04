/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:26:03 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	zero_first_next(t_control *control, int op, int up, int down)
{
	if (up <= down)
	{
		while (control->pile_a->pos != 0)
		{
			ra(control, 1);
			op++;
		}
	}
	else
	{
		while (control->pile_a->pos != 0)
		{
			rra(control, 1);
			op++;
		}
	}
	return (op);
}

int	zero_first(t_control *control, int op)
{
	int		up;
	int		down;
	t_list	*a;

	up = 0;
	down = 0;
	a = control->pile_a;
	while (a->pos != 0)
	{
		up++;
		a = a->next;
	}	
	while (a)
	{
		down++;
		a = a->next;
	}
	return (zero_first_next(control, op, up, down));
}
