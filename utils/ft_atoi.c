/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 15:00:36 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str, char **tab, t_control *control)
{
	int		i;
	long	nb;
	int		signe;

	i = 0;
	nb = 0;
	signe = 1;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10 + str[i]) - '0';
		i++;
	}
	if ((nb > 2147483647 && signe == 1) || (nb > 2147483648 && signe == -1))
	{
		ft_freetab(tab);
		ft_freestruct(control);
		ft_putstr("Error\n", 2);
	}
	return (nb * signe);
}
