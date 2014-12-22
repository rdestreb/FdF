#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 10:38:16 by rdestreb          #+#    #+#              #
#    Updated: 2014/12/22 09:27:35 by rdestreb         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
SRCDIR = ./
HEADDIR = ./
HEAD = fdf.h
HEADFILES = $(addprefix $(HEADDIR)/, $(HEAD))
SCRFILES = $(addprefix $(SRCDIR)/, $(SRC))
SRC =	main.c \
		mlx.c \
		draw.c \
		list.c \
#		play_mlx.c

OBJS = $(SCRFILES:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
LDFLAGS = -L ./libft/ -lft -L/usr/X11/lib -lmlx -lXext -lX11
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

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
