NAME	= so_long
OBJS	= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR= objs/
SRCS	= test.c
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM 		= rm -rf

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS_DIR)%.o: %.c 
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all :	$(NAME)

clean : 
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all
