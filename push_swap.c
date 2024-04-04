/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 20:09:41 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(int ac, char **av)
{
	t_control	*control;
	char		**tab;

	control = NULL;
	tab = ft_parsing(ac, av);
	control = ft_init_struct(control, tab);
	ft_get_struct(tab, control);
	ft_check_doublon(control, tab);
	ft_get_pos(control);
	ft_freetab(tab);
	algo(control);
	ft_freestruct(control);
}

int	main(int ac, char **av)
{
	ft_push_swap(ac, av);
	return (0);
}
