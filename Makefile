# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 15:03:16 by mouarar           #+#    #+#              #
#    Updated: 2024/11/29 10:09:29 by mouarar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_bonus.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARNMAE = ar rc $(NAME)

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARNMAE) $^

%.o : %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)

re : fclean all