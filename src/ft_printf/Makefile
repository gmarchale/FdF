# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:24:22 by gmarchal          #+#    #+#              #
#    Updated: 2023/05/02 16:00:13 by gmarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
 
SRCS = ft_printf.c		\
	   ft_putstr.c		\
	   ft_putnbr.c		\

OBJ = $(SRCS:.c=.o)

AR = ar -rc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

CC = cc

RM = rm -f

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re :    fclean $(NAME) 

.PHONY: all clean fclean re
