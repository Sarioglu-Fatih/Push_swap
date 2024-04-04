/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_size_chart.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:38:32 by fsariogl          #+#    #+#             */
/*   Updated: 2022/05/11 14:14:31 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_tabheight(char **tab)
{
	int	l;

	l = 0;
	while (tab[l])
		l++;
	return (l);
}

int	ft_tabsize(char	**tab)
{
	int	l;
	int	c;
	int	size;

	l = 1;
	size = 0;
	while (tab[l])
	{
		c = 0;
		while (tab[l][c])
		{
			c++;
			size++;
		}
		l++;
		size++;
	}
	return (size);
}
