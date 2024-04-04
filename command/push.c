/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:38:32 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:22:31 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_control *control, int print)
{
	t_list	*temp;

	if (ft_struct_numbers_b(control) <= 0)
		return ;
	temp = control->pile_b;
	control->pile_b = temp->next;
	if (ft_struct_numbers_a(control) <= 0)
		temp->next = NULL;
	temp->next = control->pile_a;
	control->pile_a = temp;
	if (print == 1)
		write(1, "pa\n", 3);
	ft_get_stackpos(control);
}

void	pb(t_control *control, int print)
{
	t_list	*temp;

	if (ft_struct_numbers_a(control) <= 0)
		return ;
	temp = control->pile_a;
	control->pile_a = temp->next;
	if (ft_struct_numbers_b(control) <= 0)
		temp->next = NULL;
	temp->next = control->pile_b;
	control->pile_b = temp;
	if (print == 1)
		write(1, "pb\n", 3);
	ft_get_stackpos(control);
}
