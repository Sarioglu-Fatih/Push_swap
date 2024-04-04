/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:24:02 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_control *control, int print)
{
	t_list	*lst;

	if (ft_struct_numbers_b(control) <= 1)
		return ;
	lst = control->pile_b;
	control->pile_b = lst->next;
	lst->next = NULL;
	ft_lstadd_back_b(control, lst);
	if (print == 1)
		write(1, "rb\n", 3);
	ft_get_stackpos(control);
}

void	ra(t_control *control, int print)
{
	t_list	*lst;

	if (ft_struct_numbers_a(control) <= 1)
		return ;
	lst = control->pile_a;
	control->pile_a = lst->next;
	lst->next = NULL;
	ft_lstadd_back_a(control, lst);
	if (print == 1)
		write(1, "ra\n", 3);
	ft_get_stackpos(control);
}

void	rr(t_control *control, int print)
{
	if (ft_struct_numbers_a(control) <= 1 || ft_struct_numbers_b(control) <= 1)
		return ;
	ra(control, 0);
	rb(control, 0);
	if (print == 1)
		write(1, "rr\n", 3);
	ft_get_stackpos(control);
}
