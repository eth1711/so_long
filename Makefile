NAME		= so_long
OBJS		= $(SRCS:.c=.o)
SRCS		= $(wildcard Resources/*.c) $(wildcard Resources/external_functions/*.c)
INCLUDES 	= -IResources/external_functions
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -lmlx -framework OpenGL -framework AppKit
RM			= rm -rf

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX) -o $(NAME)

all :	$(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
