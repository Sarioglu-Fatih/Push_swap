/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:57:27 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_pos(t_control *control)
{
	int		snb;
	int		temp;
	int		posx;
	t_list	*list;

	posx = 0;
	snb = ft_struct_numbers_a(control);
	list = control->pile_a;
	while (list && posx < snb)
	{
		list = control->pile_a;
		temp = 2147483647;
		while (list)
		{
			if (list->pos == -1 && list->nb < temp)
				temp = list->nb;
			list = list->next;
		}
		list = control->pile_a;
		while (list && temp != list->nb)
				list = list->next;
		list->pos = posx;
		posx++;
	}
}
