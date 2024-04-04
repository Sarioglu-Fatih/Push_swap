NAME = push_swap

BONUS = checker

SRC =		push_swap.c					\
			utils/ft_atoi.c				\
			utils/ft_lstadd_back.c		\
			utils/ft_freetab.c			\
        	utils/ft_putstr.c			\
        	parsing/ft_split_tab.c		\
        	utils/ft_split.c			\
        	utils/ft_tab_size_chart.c	\
			parsing/ft_get_struct.c		\
			parsing/ft_check_doublon.c	\
			parsing/ft_parsing.c		\
			parsing/ft_pos_struct.c		\
			command/swap.c				\
			command/push.c				\
			command/reverse_rotate.c	\
			command/rotate.c			\
			algo/ft_lowcase.c			\
			algo/case2to4.c				\
			algo/find_closer.c			\
			utils/ft_pos_stack.c		\
			utils/ft_struct_numbers_c.c	\
			utils/ft_struct_numbers.c	\
			algo/algo.c					\
			algo/case3_b.c				\
			algo/zero_first.c			\
			algo/pack.c					\
			algo/ft_total_low_case.c	\
			utils/ft_sorted.c			\
			algo/push_closer.c			\
			algo/case5to10.c			\
			algo/lowcase_algo.c			\
			algo/score.c				\
			algo/find_closer_next.c		\


BONUS_SRC =	utils/ft_atoi.c				\
			utils/ft_lstadd_back.c		\
			utils/ft_freetab.c			\
			utils/ft_putstr.c			\
			parsing/ft_split_tab.c		\
			utils/ft_split.c			\
			utils/ft_tab_size_chart.c	\
			parsing/ft_get_struct.c		\
			parsing/ft_check_doublon.c	\
			parsing/ft_parsing.c		\
			parsing/ft_pos_struct.c		\
			utils/ft_struct_numbers_c.c	\
			utils/ft_sorted.c			\
			utils/ft_pos_stack.c		\
			command/swap.c				\
			command/push.c				\
			command/reverse_rotate.c	\
			command/rotate.c			\
			bonus/checker.c				\
			bonus/get_next_line_utils.c	\
			bonus/get_next_line.c		\



HEADER = ./push_swap.h

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o : %.c $(HEADER) Makefile
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile
	mkdir -p ./obj/
	gcc $(CFLAGS) -o $(NAME) $(OBJS)
	mv ./*/*.o ./obj/.

bonus: $(BONUS_OBJS) $(HEADER) Makefile
	mkdir -p ./obj/
	gcc -o $(BONUS) $(CFLAGS) $(BONUS_OBJS)
	mv ./*/*.o ./obj/.

all: $(NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) ./obj/

fclean: clean
	rm -rf $(NAME) $(BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
