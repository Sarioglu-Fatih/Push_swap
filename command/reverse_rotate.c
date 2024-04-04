/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 15:22:48 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_control *control, int print)
{
	t_list	*lst;
	t_list	*temp;

	if (ft_struct_numbers_b(control) <= 1)
		return ;
	lst = ft_lstlast(control->pile_b);
	temp = control->pile_b;
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	lst->next = control->pile_b;
	control->pile_b = lst;
	if (print == 1)
		write(1, "rrb\n", 4);
	ft_get_stackpos(control);
}

void	rra(t_control *control, int print)
{
	t_list	*lst;
	t_list	*temp;

	if (ft_struct_numbers_a(control) <= 1)
		return ;
	lst = ft_lstlast(control->pile_a);
	temp = control->pile_a;
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	lst->next = control->pile_a;
	control->pile_a = lst;
	if (print == 1)
		write(1, "rra\n", 4);
	ft_get_stackpos(control);
}

void	rrr(t_control *control, int print)
{
	if (ft_struct_numbers_a(control) <= 1 || ft_struct_numbers_b(control) <= 1)
		return ;
	rra(control, 0);
	rrb(control, 0);
	if (print == 1)
		write(1, "rrr\n", 4);
	ft_get_stackpos(control);
}
