# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 15:22:24 by gmarchal          #+#    #+#              #
#    Updated: 2023/05/02 15:30:25 by gmarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp \
	    ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
		ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat \
		ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strtrim \
		ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		ft_putnbr_fd ft_striteri

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:.c=.o)

BONUS_FILES = ft_lstnew ft_lstsize ft_lstmap ft_lstlast ft_lstiter ft_lstdelone \
			  ft_lstclear ft_lstadd_front ft_lstadd_back

BONUS_SRCS = $(addsuffix _bonus.c, $(BONUS_FILES))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werrora #-fsanitize=address -g

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
