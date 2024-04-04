/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_low_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2024/04/04 12:10:30 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_total_lowcase(t_control *control, int op)
{
	if (!control->pile_a)
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
	{
		op = case4(control, op);
	}
	return (op);
}
