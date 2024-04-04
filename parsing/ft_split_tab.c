/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/02 19:28:38 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_split_tab_next(char **tab, char *str, int i)
{
	str[i] = '\0';
	tab = ft_split(str, ' ');
	free(str);
	return (tab);
}

char	**ft_split_tab(char **tab)
{
	int		c;
	int		l;
	int		i;
	char	*str;

	str = malloc(sizeof(char) * ft_tabsize(tab) + 1);
	if (!str)
		exit(EXIT_FAILURE);
	i = 0;
	l = 1;
	while (tab[l])
	{
		c = 0;
		while (tab[l][c])
		{
			str[i] = tab[l][c];
			i++;
			c++;
		}
		str[i] = ' ';
		l++;
		i++;
	}
	return (ft_split_tab_next(tab, str, i));
}
