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
#NAME_BONUS = checker

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
#HEADER_BONUS = include/push_swap_bonus.h
SRCS = src/fract_ol.c src/handle_events.c src/fractals.c src/color.c \
		src/events_bonus.c src/fractal_bonus.c
OBJS = $(SRCS:.c=.o)
#SRCS_BONUS = src_bonus/checker_bonus.c src_bonus/push_bonus.c \
			src_bonus/swap_bonus.c src_bonus/rotate_bonus.c \
			src_bonus/reverse_rotate_bonus.c src_bonus/init_stacks_bonus.c \
			src_bonus/swap_utils_bonus.c src_bonus/verify_input_bonus.c \
			src_bonus/verify_input_aux_bonus.c \
			src_bonus/get_next_line_bonus.c
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

#bonus: $(NAME_BONUS)

#$(NAME_BONUS): $(OBJS_BONUS)
#	$(MAKE) -C libft
#	cp libft/libft.a libft.a
#	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) libft.a

src/%.o: src/%.c $(HEADER)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

#src_bonus/%.o: src_bonus/%.c $(HEADER_BONUS)
#	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

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
