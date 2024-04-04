/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/07 15:41:34 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_first3(t_control *control, int op)
{
	pa(control, 1);
	pa(control, 1);
	pa(control, 1);
	op = op + 3;
	ft_get_stackpos(control);
	op = case3_b(control, op, control->pile_a);
	return (op);
}

int	get_closer(t_control *control, int op, int size, int tsize)
{
	int	*finder;
	int	dif;

	dif = tsize - size;
	finder = malloc(sizeof(int) * 4);
	if (!finder)
	{
		ft_freestruct(control);
		return (0);
	}
	op = push_first3(control, op);
	while (control->pile_b)
	{
		finder = find_closer(control->pile_a, control->pile_b, finder, size);
		op = push_closer(control, finder, op);
		tsize--;
		if (size == tsize - 3)
			size = size - dif;
	}
	free(finder);
	return (op);
}

int	pack_numbers(int size)
{
	size = size / 50;
	if (size % 2 == 1)
		size++;
	return (size);
}

int	case10to50(t_control *control, int op, int size)
{
	while (control->pile_a)
	{
		op++;
		pb(control, 1);
	}
	op = get_closer(control, op, -1, size);
	return (op);
}

void	algo(t_control *control)
{
	int	op;
	int	size;
	int	pack_nb;

	op = 0;
	size = ft_struct_numbers_a(control);
	if (!control->pile_a)
		return ;
	if (sorted(control) == 0)
		return ;
	ft_get_stackpos(control);
	pack_nb = pack_numbers(size);
	if (size <= 4)
		op = ft_total_lowcase(control, op);
	else if (size > 4 && size <= 5)
		op = case5to10(control, op, size);
	else if (size <= 50)
		op = case10to50(control, op, size);
	else
	{
		op = pack(control, pack_nb, op, size / pack_nb);
		op = get_closer(control, op, size / pack_nb, size);
	}
	op = zero_first(control, op);
}
