/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:38:32 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:56:39 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_doublon(t_control *control, char **tab)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*check;

	i = 0;
	tmp = control->pile_a;
	while (tmp)
	{
		j = 0;
		check = control->pile_a;
		while (check)
		{
			if (check->nb == tmp->nb && i != j)
			{
				ft_freetab(tab);
				ft_freestruct(control);
				ft_putstr("Error\n", 2);
			}
			check = check->next;
			j++;
		}
		tmp = tmp->next;
		i++;
	}
}
