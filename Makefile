#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 10:38:16 by rdestreb          #+#    #+#              #
#    Updated: 2015/12/17 19:07:29 by rdestreb         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
SRCDIR = ./src
HEADDIR = ./src
HEAD = fdf.h
HEADFILES = $(addprefix $(HEADDIR)/, $(HEAD))
SCRFILES = $(addprefix $(SRCDIR)/, $(SRC))
SRC =	main.c \
		mlx.c \
		hook.c \
		draw.c \
		list.c \
		params.c \
		image.c

OBJS = $(SCRFILES:.c=.o)
CC = clang
CFLAGS = -O3 -Wall -Werror -Wextra
LDFLAGS = -L ./libft/ -lft -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJS)

$(LIBFT):
	$(MAKE) -C ./libft/

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C ./libft/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft/ $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
