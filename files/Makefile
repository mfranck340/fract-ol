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

MLX = libmlx42.a
MLX_DIR = MLX42
MLX_FLAGS = -ldl -lglfw -pthread -lm

CC = cc
LIB = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

HEADER = include/fract_ol.h
#HEADER_BONUS = include/push_swap_bonus.h
SRCS = src/fract_ol.c
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

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
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	$(MAKE) -C $(MLX_DIR)/build -j4
	cp $(MLX_DIR)/build/$(MLX) $(MLX)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(MLX_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT) $(MLX)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
