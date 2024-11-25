# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 12:12:02 by mouarar           #+#    #+#              #
#    Updated: 2024/11/25 18:04:02 by mouarar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c
BONUS = ft_printf_bonus.c ft_printf_bonus_utils_1.c fake_bonus.c ft_printf_utils.c ft_printf_bonus_utils_2.c

OBJS := $(SRC:%.c=%.o)
BONUS_OBJS := $(BONUS:%.c=%.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARNMAE = ar crs $(NAME)

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARNMAE) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus :	$(BONUS_OBJS)
	$(ARNMAE) $(BONUS_OBJS)

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
.PHONY : clean