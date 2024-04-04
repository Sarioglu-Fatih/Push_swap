/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:24:48 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_control *control, int print)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	if (ft_struct_numbers_b(control) <= 1)
		return ;
	one = control->pile_b;
	two = one->next;
	three = two->next;
	control->pile_b = two;
	control->pile_b->next = one;
	control->pile_b->next->next = three;
	if (print == 1)
		write(1, "sb\n", 3);
	ft_get_stackpos(control);
}

void	sa(t_control *control, int print)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	if (ft_struct_numbers_a(control) <= 1)
		return ;
	one = control->pile_a;
	two = one->next;
	three = two->next;
	control->pile_a = two;
	control->pile_a->next = one;
	control->pile_a->next->next = three;
	if (print == 1)
		write(1, "sa\n", 3);
	ft_get_stackpos(control);
}

void	ss(t_control *control, int print)
{
	if (ft_struct_numbers_a(control) > 1 && ft_struct_numbers_b(control) > 1)
	{
		sa(control, 0);
		sb(control, 0);
		if (print == 1)
			write(1, "ss\n", 3);
		ft_get_stackpos(control);
	}
}
