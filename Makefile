# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewonki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:36:20 by jaewonki          #+#    #+#              #
#    Updated: 2022/05/06 12:36:31 by jaewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MFLAGS	= -framework OpenGL -framework AppKit

FT_DIR	= ./lib/Libft
GNL_DIR	= ./lib/libgnl	
MLX_DIR	= ./lib/libmlx
FT		= ft
GNL		= gnl
MLX 	= mlx

INCLUDE = -I./include

SRC_DIR = ./src
SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/map.c \
	$(SRC_DIR)/img.c \
	$(SRC_DIR)/draw.c \
	$(SRC_DIR)/move.c \
	$(SRC_DIR)/check.c \
	$(SRC_DIR)/player.c \
	$(SRC_DIR)/close.c \
	$(SRC_DIR)/key_press.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(FT_DIR) 
	$(MAKE) -C $(GNL_DIR) 
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ \
		-L$(FT_DIR) -l$(FT) \
		-L$(GNL_DIR) -l$(GNL) \
		-L$(MLX_DIR) -l$(MLX) $(MFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	
clean:
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
