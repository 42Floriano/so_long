# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:30:56 by falberti          #+#    #+#              #
#    Updated: 2024/02/23 16:37:13 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR		=	sources
lIBRARIES_DIR	=	libraries

HEADER = $(lIBRARIES_DIR)/so_long.h

FILES = $(SOURCES_DIR)/init\
				$(SOURCES_DIR)/commands\
				$(SOURCES_DIR)/color_screen\
				$(SOURCES_DIR)/player_update\

## This is a bit tricky for me but it ask to check the end of the string in FILES than add .c if there is nothing
## Also possible to just liste the .c and .o files
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -Imlx 
NAME = so_long

#####################################################################
## Rules

MINILIBFT = includes/libftmini/libftmini.a


all: $(NAME)

$(NAME): $(OFILES)
		$(CC) $(OFILES) $(MINILIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

### For each .o file  it needs the .c file | $< is automatic var that takes the param and $@ the target
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

## Tells the Makefiles that all(all, clean, fclean, re) are not files but just rules
.PHONY: all clean fclean re