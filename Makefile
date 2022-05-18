NAME = stats
SOURCES = main.c mlx.c render.c ./sources/parser.c ./sources/utilities.c ./sources/stat_output.c ./sources/options_handling.c
INCLUDES = fb_stats.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror 
LINKS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext

$(NAME):
	gcc -o $(NAME) $(LINKS) $(SOURCES) $(LIBFT)

clean:
	rm -f stats 

re: clean $(NAME)
