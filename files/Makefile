# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 17:42:15 by ffierro-          #+#    #+#              #
#    Updated: 2024/12/26 17:42:16 by ffierro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a
LIBFT_DIR = libft

MLX = libmlx.a
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

CC = cc
LIB = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

HEADER = include/fract_ol.h
SRCS = src/fract_ol.c src/handle_events.c src/fractals.c src/color.c \
		src/events_bonus.c src/fractal_bonus.c src/parse_double.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

src/%.o: src/%.c $(HEADER)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
