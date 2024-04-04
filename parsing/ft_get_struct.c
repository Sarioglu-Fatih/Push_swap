/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:38:32 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:58:00 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *sptr)
{
	if (!sptr)
		return (NULL);
	while (sptr->next)
		sptr = sptr->next;
	return (sptr);
}

t_control	*ft_init_struct(t_control *control, char **tab)
{
	control = malloc(sizeof(t_control));
	if (!control)
	{
		ft_freetab(tab);
		exit(EXIT_FAILURE);
	}
	control->pile_a = NULL;
	control->pile_b = NULL;
	return (control);
}

t_list	*ft_lstnew(int nb, char **tab, t_control *control)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
	{
		ft_freetab(tab);
		ft_freestruct(control);
		exit(EXIT_FAILURE);
	}
	lst->nb = nb;
	lst->pos = -1;
	lst->next = NULL;
	return (lst);
}

void	ft_get_struct(char **tab, t_control *control)
{
	int	l;

	l = 0;
	while (tab[l])
	{
		ft_lstadd_back_a(control, ft_lstnew(ft_atoi(tab[l], tab, control),
				tab, control));
		l++;
	}
}
