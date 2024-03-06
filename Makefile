# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albertini <albertini@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:30:56 by falberti          #+#    #+#              #
#    Updated: 2024/03/06 11:42:21 by albertini        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR		=	sources
lIBRARIES_DIR	=	libraries

HEADER = $(lIBRARIES_DIR)/so_long.h

FILES = $(SOURCES_DIR)/main\
				$(SOURCES_DIR)/commands\
				$(SOURCES_DIR)/player_update\
				$(SOURCES_DIR)/map_checker\
				$(SOURCES_DIR)/read_map\
				$(SOURCES_DIR)/path_checker\
				$(SOURCES_DIR)/exit_free_game\
				$(SOURCES_DIR)/init_game\
				$(SOURCES_DIR)/init_struct\
				$(SOURCES_DIR)/draw_map\

## This is a bit tricky for me but it ask to check the end of the string in FILES than add .c if there is nothing
## Also possible to just liste the .c and .o files
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -Imlx -g
NAME = so_long

#####################################################################
## Rules

MINILIBFT = includes/libftmini/libftmini.a

$(MINILIBFT):
	$(MAKE) -C includes/libftmini


all: $(NAME)

$(NAME): $(OFILES) $(MINILIBFT)
		$(CC) $(OFILES) $(MINILIBFT) -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

### For each .o file  it needs the .c file | $< is automatic var that takes the param and $@ the target
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C includes/libftmini clean
		rm -f $(OFILES)

fclean: clean
		$(MAKE) -C includes/libftmini fclean
		rm -f $(NAME)

re: fclean all

## Tells the Makefiles that all(all, clean, fclean, re) are not files but just rules
.PHONY: all clean fclean re