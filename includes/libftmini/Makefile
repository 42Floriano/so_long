FILES = ft_split\
            ft_strdup\
            ft_strjoin\
            ft_strlen\
            get_next_line\
            get_next_line_utils\

			
CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Target library
NAME = libftmini.a

# Build rule for the library
all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $@ $(OFILES)

# Build rule for object files
$(FILES).o: $(FILES).c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	@rm -f $(OFILES)

# Clean rule to remove object bonus files
bclean:
	@rm -f $(BONUS_OBJS)

# Full clean rule to remove object files and the library
fclean: clean
	@rm -f $(NAME)

# Rebuild rule
re: fclean all

bonus:            $(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus