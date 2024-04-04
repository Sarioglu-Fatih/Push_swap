/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 16:04:33 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_control *control)
{
	t_list	*a;

	a = control->pile_a;
	if (!a || !a->next)
		return (0);
	while (a->next->next && a->nb < a->next->nb)
		a = a->next;
	if (a->nb < a->next->nb && !(a->next->next))
		return (0);
	return (1);
}
