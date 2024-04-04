/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/06 16:03:52 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	move(t_control *control, char *str)
{
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr(control, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(control, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(control, 0);
	else if (str[0] == 'r' && str[1] == 'r')
		rr(control, 0);
	else if (str[0] == 'r' && str[1] == 'a')
		ra(control, 0);
	else if (str[0] == 'r' && str[1] == 'b')
		rb(control, 0);
	else if (str[0] == 's' && str[1] == 's')
		ss(control, 0);
	else if (str[0] == 's' && str[1] == 'a')
		sa(control, 0);
	else if (str[0] == 's' && str[1] == 'b')
		sb(control, 0);
	else if (str[0] == 'p' && str[1] == 'a')
		pa(control, 0);
	else if (str[0] == 'p' && str[1] == 'b')
		pb(control, 0);
	else
		return (0);
	return (1);
}

void	checker2(t_control *control)
{
	char	*str;
	int		check;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		check = move(control, str);
		if (str[0] == '\0' || !str)
		{
			ft_freestruct(control);
			return ;
		}
		if (check == 0)
		{
			ft_freestruct(control);
			free(str);
			ft_putstr("Error\n", 2);
		}
		free(str);
	}
}

void	checker(int ac, char **av)
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
	checker2(control);
	if (sorted(control) == 0 && !control->pile_b)
		printf("OK\n");
	else
		printf("KO\n");
	ft_freestruct(control);
}

int	main(int ac, char **av)
{
	checker(ac, av);
	return (0);
}
