/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:28:11 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	tab[0] = up;
	tab[1] = down;
	tab[2] = mid;
	tab[3] = temp;
*/

void	define_limit(int *tab, int div, int size)
{
	tab[0] = size * (div / 2) - size;
	tab[1] = size * (div / 2) + size;
	tab[2] = size * (div / 2);
}

int	pack4(t_control *control, int op)
{
	rb(control, 1);
	op++;
	return (op);
}

int	pack3(t_control *control, int op, int *tab)
{
	if (control->pile_a->pos >= tab[2] && control->pile_a->pos <= tab[1])
	{
		op++;
		pb(control, 1);
		tab[3]--;
	}
	else
	{
		op++;
		ra(control, 1);
		tab[3]--;
	}
	return (op);
}

int	pack2(t_control *control, int op, int *tab)
{
	if (control->pile_a->pos >= tab[0] && control->pile_a->pos < tab[2])
	{
		op++;
		tab[3]--;
		pb(control, 1);
		if (control->pile_a)
		{
			if (control->pile_b->pos < tab[2] && (control->pile_a->pos < tab[0]
					|| control->pile_a->pos > tab[1]))
			{	
				rr(control, 1);
				tab[3]--;
				op++;
			}
			else
				op = pack4(control, op);
		}
		else
			op = pack4(control, op);
	}
	return (op);
}

int	pack(t_control *control, int div, int op, int size)
{
	int		tab[4];

	define_limit(tab, div, size);
	while (tab[0] >= 0)
	{
		tab[3] = ft_struct_numbers_a(control);
		while (tab[3] >= 0 && control->pile_a)
		{
			if (control->pile_a->pos >= tab[0] && control->pile_a->pos < tab[2])
				op = pack2(control, op, tab);
			else
				op = pack3(control, op, tab);
		}
		tab[0] = tab[0] - size;
		tab[1] = tab[1] + size;
	}
	while (control->pile_a)
	{
		pb(control, 1);
		op++;
	}
	define_limit(tab, div, size);
	return (op);
}
