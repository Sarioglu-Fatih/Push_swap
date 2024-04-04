/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2024/04/04 12:43:37 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_is_num_next(char *av, int c)
{
	if ((av[c] == '+' || av[c] == '-') && (!(av[c + 1] >= '0'
				&& av[c + 1] <= '9')))
		ft_putstr("Error\n", 2);
	if ((av[c] == '+' || av[c] == '-') && c > 0 && av[c - 1] != ' ')
		ft_putstr("Error\n", 2);
}

void	ft_is_num(char **av)
{
	int	c;
	int	l;

	c = 0;
	l = 1;
	while (av[l])
	{
		c = 0;
		while (av[l][c])
		{
			ft_is_num_next(av[l], c);
			if ((av[l][c] >= '0' && av[l][c] <= '9') || av[l][c] == ' '
					|| av[l][c] == '+' || av[l][c] == '-')
				c++;
			else
				ft_putstr("Error\n", 2);
		}
		l++;
	}
}

void	ft_is_biger(char **av)
{
	int	c;
	int	l;
	int	s;

	c = 0;
	l = 1;
	while (av[l])
	{
		s = 0;
		c = 0;
		while (av[l][c])
		{
			if (av[l][c] >= '0' && av[l][c] <= '9')
				s++;
			else
				s = 0;
			if (s > 10)
				ft_putstr("Error\n", 2);
			c++;
		}
		l++;
	}
}

int	ft_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_parsing(int ac, char **av)
{
	char	**tab;

	if (ac <= 1)
		exit(EXIT_SUCCESS);
	ft_is_num(av);
	ft_is_biger(av);
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
		tab = ft_split_tab(av);
	return (tab);
}
