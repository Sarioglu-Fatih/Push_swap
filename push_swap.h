/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:08:10 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/07 20:08:13 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	int				pos;
	int				spos;
	int				*temp;
	struct s_list	*next;
}		t_list;

typedef struct s_control
{
	t_list			*pile_a;
	t_list			*pile_b;
}		t_control;

char		**ft_parsing(int ac, char **av);
void		ft_putchar(char c, int fd);
void		ft_putstr(char *str, int fd);
void		ft_is_num(char **av);
void		ft_is_biger(char **av);
int			ft_count_words(char *s, char c);
int			ft_atoi(char *str, char **tab, t_control *control);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		ft_lstadd_back_a(t_control *control, t_list *new);
void		ft_lstadd_back_b(t_control *control, t_list *new);
t_list		*ft_lstlast(t_list *sptr);
void		*ft_calloc(size_t count, size_t size);
void		ft_freetab(char **tab);
void		ft_freestruct(t_control *control);
int			ft_tabsize(char	**tab);
char		**ft_split(char *str, char c);
char		**ft_split_tab(char **tab);
int			ft_count_words(char *s, char c);
void		ft_get_struct(char **tab, t_control *control);
t_control	*ft_init_struct(t_control *control, char **tab);
void		ft_check_doublon(t_control *control, char **tab);
void		ft_get_pos(t_control *control);
int			ft_struct_numbers_a(t_control *control);
int			ft_struct_numbers_b(t_control *control);
void		ft_get_stackpos(t_control *control);
void		sa(t_control *control, int print);
void		sb(t_control *control, int print);
void		ss(t_control *control, int print);
void		pa(t_control *control, int print);
void		pb(t_control *control, int print);
void		ra(t_control *control, int print);
void		rb(t_control *control, int print);
void		rr(t_control *control, int print);
void		rra(t_control *control, int print);
void		rrb(t_control *control, int print);
void		rrr(t_control *control, int print);
int			sorted(t_control *control);
void		algo2(t_control *control);
int			ft_lowcase(t_control *control, int op);
int			case4(t_control *control, int op);
int			case3(t_control *control, int op);
int			case2(t_control *control, int op);
int			push0(t_control *control, int op);
void		algo(t_control *control);
int			*find_closer(t_list *a, t_list *b, int *finder, int size);
int			push_closer(t_control *control, int *finder, int op);
int			case3_b(t_control *control, int op, t_list *lst);
int			zero_first(t_control *control, int op);
int			pack(t_control *control, int div, int op, int size);
int			ft_struct_numbers(t_list *lst);
int			ft_total_lowcase(t_control *control, int op);
int			push_closer(t_control *control, int *finder, int op);
int			case5to10(t_control *control, int op, int size);
int			lowcase_algo(t_control *control, int op);
void		score2(int (*score)[5], int **finder, int *upord, int *limit);
void		score1(int (*score)[5], int **finder, int *upord, int *limit);
void		score3(int (*score)[5], int **finder, int *upord, t_list *b);
void		score4(int (*score)[5], int **finder, int *upord, t_list *b);
void		find_closer6(int (*limit)[2], int size, t_list **temp, t_list *a);
void		find_closer7(t_list **b, int (*limit)[2]);
void		find_closer8(t_list **a, int (*upord)[2]);
char		**ft_parsing(int ac, char **av);
int			ft_strlennl(char *str, int nb);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
void		raz(char *buff);
char		*get_next_line(int fd);
int			ft_strlennl(char *str, int nb);

#endif
