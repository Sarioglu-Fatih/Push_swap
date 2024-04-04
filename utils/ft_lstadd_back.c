/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 15:01:02 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back_b(t_control *control, t_list *new)
{
	t_list	*sptr;

	if (!control->pile_b)
	{
		control->pile_b = new;
		return ;
	}
	sptr = control->pile_b;
	sptr = ft_lstlast(sptr);
	sptr->next = new;
}

void	ft_lstadd_back_a(t_control *control, t_list *new)
{
	t_list	*sptr;

	if (!control->pile_a)
	{
		control->pile_a = new;
		return ;
	}
	sptr = control->pile_a;
	sptr = ft_lstlast(sptr);
	sptr->next = new;
}
