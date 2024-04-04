/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 11:33:28 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
score[0]	= top score
score[1]	= up	A	up		B
score[2]	= down	A	up		B
score[3]	= up	A	down	B
score[4]	= down	A	down	B

finder[0]	= mv	A
finder[1]	= mv	B
finder[2]	= pos or neg for A
finder[3]	= pos or neg for B

upord[0]	= up
upord[1]	= down
*/

int	find_closer2(t_list ***a, t_list *temp, int *upord)
{
	(**a) = temp;
	upord[0] = 0;
	while ((**a)->pos < (**a)->next->pos && (**a)->next->next)
	{
		upord[0]++;
		(**a) = (**a)->next;
	}
	if ((**a)->pos < (**a)->next->pos)
	{
		upord[0]++;
		(**a) = (**a)->next;
	}
	if ((**a)->next)
	{
		if ((**a)->pos > (**a)->next->pos)
		{
			upord[0]++;
			(**a) = (**a)->next;
		}
	}
	else
		upord[0] = 0;
	return (upord[0]);
}

void	find_closer4(int (*score)[5], int (*upord)[2], int *limit)
{
	if ((*upord)[1] < 1)
		(*upord)[0] = 0;
	if ((*upord)[0] > limit[0])
		(*score)[1] = (*upord)[0];
	else
		(*score)[1] = limit[0];
	(*score)[2] = (*upord)[1] + limit[0];
}

void	find_closer5(int (*score)[5], t_list *b, int *upord)
{
	(*score)[3] = upord[0] + ft_struct_numbers(b);
	if (upord[1] > ft_struct_numbers(b))
		(*score)[4] = upord[1];
	else
		(*score)[4] = ft_struct_numbers(b);
}

void	find_closer3(t_list **a, t_list *b, t_list *temp, int *upord)
{
	t_list	***ptr;

	upord[1] = 0;
	(*a) = temp;
	while ((*a)->next->next && !(b->pos > (*a)->pos && b->pos
			< (*a)->next->pos))
	{
		(*a) = (*a)->next;
		upord[0]++;
	}
	if (b->pos > (*a)->pos && b->pos < (*a)->next->pos)
	{
		(*a) = (*a)->next;
		upord[0]++;
	}
	else if (b->pos > (*a)->next->pos && b->pos < temp->pos)
		upord[0] = 0;
	else if (!(b->pos > (*a)->pos && b->pos < (*a)->next->pos))
	{
		ptr = &a;
		upord[0] = find_closer2(&*ptr, temp, upord);
	}
}

int	*find_closer(t_list *a, t_list *b, int *finder, int size)
{
	int		upord[2];
	int		limit[2];
	int		score[5];
	t_list	*temp;

	find_closer6(&limit, size, &temp, a);
	score[0] = 2000000;
	while (b)
	{
		upord[0] = 0;
		find_closer3(&a, b, temp, upord);
		find_closer8(&a, &upord);
		find_closer4(&score, &upord, limit);
		find_closer5(&score, b, upord);
		if (score[2] < score[0] && b->pos >= size)
			score2(&score, &finder, upord, limit);
		if (score[1] < score[0] && b->pos >= size)
			score1(&score, &finder, upord, limit);
		if (score[3] < score[0] && b->pos >= size)
			score3(&score, &finder, upord, b);
		if (score[4] < score[0] && b->pos >= size)
			score4(&score, &finder, upord, b);
		find_closer7(&b, &limit);
	}
	return (finder);
}
