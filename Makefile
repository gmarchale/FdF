# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 15:22:24 by gmarchal          #+#    #+#              #
#    Updated: 2023/04/19 15:22:42 by gmarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

FILES	= main.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

SRC_DIR	= src
OBJDIR		= obj
INCDIR		= ${FT_PRINTF_DIR} ${LIBFT_DIR} ${GNL_DIR} src/mlx/mlx_macos

SRC		= $(addprefix ${SRC_DIR}/, ${FILES})
OBJ		= $(addprefix ${OBJDIR}/, $(addsuffix .o, $(basename ${FILES})))
OBJ_DIR	= $(sort $(dir $(OBJ)))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= $(foreach d, $(INCDIR), -I$d)

# libft
LIBFT_DIR	= src/libft
LIBFT		= ${LIBFT_DIR}/libft.a

# ft_printf
FT_PRINTF_DIR	= src/ft_printf
FT_PRINTF		= ${FT_PRINTF_DIR}/libftprintf.a

# GNL
GNL_DIR		= src/get_next_line

# Minilibx
MLX_DIR		= mlx/mlx_macos

MLX_PATH 	= $(MLX_DIR)/libmlx.a

MLX			= -framework OpenGL -framework AppKit ${MLX_PATH}

# Rules
${OBJDIR}/%.o: ${SRC_DIR}/%.c
			@mkdir -p ${OBJDIR} ${OBJ_DIR}
			${CC} ${CFLAGS} ${INCS} -c -o $@ $<

all:		${NAME}

${NAME}:	${OBJ}
			@make -C ${MLX_DIR}
			@make -C ${LIBFT_DIR}
			@make -C ${FT_PRINTF_DIR}
			${CC} ${OBJ} ${LIBFT} ${FT_PRINTF} ${MLX} -o ${NAME}

clean:
			@make clean -C ${MLX_DIR}
			@make clean -C ${FT_PRINTF_DIR}
			@make clean -C ${LIBFT_DIR}
			rm -rf ${OBJDIR}

fclean:		clean
			@make fclean -C ${LIBFT_DIR}
			@make fclean -C ${FT_PRINTF_DIR}
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME
