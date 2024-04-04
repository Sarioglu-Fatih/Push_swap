/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_numbers_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:38:32 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 15:02:42 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_struct_numbers_a(t_control *control)
{
	int		nb;
	t_list	*lst;

	nb = 0;
	lst = control->pile_a;
	while (lst)
	{
		nb++;
		lst = lst->next;
	}
	return (nb);
}

int	ft_struct_numbers_b(t_control *control)
{
	int		nb;
	t_list	*lst;

	nb = 0;
	lst = control->pile_b;
	while (lst)
	{
		nb++;
		lst = lst->next;
	}
	return (nb);
}
