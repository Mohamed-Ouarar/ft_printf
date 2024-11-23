# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 12:12:02 by mouarar           #+#    #+#              #
#    Updated: 2024/11/18 12:12:02 by mouarar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c

NAME = libftprintf.a
OBJS := $(SRC:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARNMAE = ar crs $(NAME)

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARNMAE) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)
.PHONY : clean