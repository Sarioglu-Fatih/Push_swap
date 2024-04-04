/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 15:00:54 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_freestruct(t_control *control)
{
	t_list	*pointeur;
	t_list	*tmp;

	pointeur = control->pile_a;
	while (pointeur)
	{
		tmp = pointeur;
		pointeur = pointeur->next;
		free(tmp);
	}
	pointeur = control->pile_b;
	while (pointeur)
	{
		tmp = pointeur;
		pointeur = pointeur->next;
		free(tmp);
	}
	free(control);
}
