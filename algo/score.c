/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:35:48 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 14:25:50 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	score2(int (*score)[5], int **finder, int *upord, int *limit)
{
	(*score)[0] = (*score)[2];
	(*finder)[0] = upord[1];
	(*finder)[1] = limit[0];
	(*finder)[2] = -1;
	(*finder)[3] = 1;
}

void	score1(int (*score)[5], int **finder, int *upord, int *limit)
{
	(*score)[0] = (*score)[1];
	(*finder)[0] = upord[0];
	(*finder)[1] = limit[0];
	(*finder)[2] = 1;
	(*finder)[3] = 1;
}

void	score3(int (*score)[5], int **finder, int *upord, t_list *b)
{
	(*score)[0] = (*score)[3];
	(*finder)[0] = upord[0];
	(*finder)[1] = ft_struct_numbers(b);
	(*finder)[2] = 1;
	(*finder)[3] = -1;
}

void	score4(int (*score)[5], int **finder, int *upord, t_list *b)
{
	(*score)[0] = (*score)[4];
	(*finder)[0] = upord[1];
	(*finder)[1] = ft_struct_numbers(b);
	(*finder)[2] = -1;
	(*finder)[3] = -1;
}
