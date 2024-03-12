# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:30:56 by falberti          #+#    #+#              #
#    Updated: 2024/03/12 14:05:45 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR		=	sources
SOURCES_BDIR		=	sources_bonus
lIBRARIES_DIR	=	libraries

HEADER = $(lIBRARIES_DIR)/so_long.h
BHEADER = $(lIBRARIES_DIR)/so_long_bonus.h

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

## Bonus
BFILES = $(SOURCES_BDIR)/main_bonus\
				$(SOURCES_BDIR)/commands_bonus\
				$(SOURCES_BDIR)/player_update_bonus\
				$(SOURCES_BDIR)/map_checker_bonus\
				$(SOURCES_BDIR)/read_map_bonus\
				$(SOURCES_BDIR)/path_checker_bonus\
				$(SOURCES_BDIR)/exit_free_game_bonus\
				$(SOURCES_BDIR)/init_game_bonus\
				$(SOURCES_BDIR)/init_struct_bonus\
				$(SOURCES_BDIR)/draw_map_bonus\
				$(SOURCES_BDIR)/draw_score_bonus\
## This is a bit tricky for me but it ask to check the end of the string in FILES than add .c if there is nothing
## Also possible to just liste the .c and .o files
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

## Bonus
BCFILES = $(addsuffix .c, $(BFILES))
BOFILES = $(addsuffix .o, $(BFILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -Imlx -g
BCFLAGS = -Werror -Wextra -Wall -I $(BHEADER) -Imlx -g
NAME = so_long
BNAME = so_long_bonus

#####################################################################
## Rules

MINILIBFT = includes/libftmini/libftmini.a

$(MINILIBFT):
	$(MAKE) -C includes/libftmini

all: FLAGS = $(CFLAGS)
all: $(NAME)

$(NAME): $(OFILES) $(MINILIBFT)
		$(CC) $(OFILES) $(MINILIBFT) -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

### For each .o file  it needs the .c file | $< is automatic var that takes the param and $@ the target
%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(MAKE) -C includes/libftmini clean
		rm -f $(OFILES)

fclean: clean
		$(MAKE) -C includes/libftmini fclean
		rm -f $(NAME)

re: fclean all

bonus: FLAGS = $(BCFLAGS)
bonus: $(BNAME)

$(BNAME): $(BOFILES) $(MINILIBFT)
		$(CC) $(BOFILES) $(MINILIBFT) -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BNAME)
bclean:
		$(MAKE) -C includes/libftmini clean
		rm -f $(BOFILES)
bfclean: bclean
		$(MAKE) -C includes/libftmini fclean
		rm -f $(BNAME)
bre: bfclean bonus

## Tells the Makefiles that all(all, clean, fclean, re) are not files but just rules
.PHONY: all clean fclean re bonus bclean bfclean bre