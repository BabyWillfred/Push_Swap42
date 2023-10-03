NAME = push_swap

SRC	=	push_swap.c check_arg.c utils.c utils2.c utils3.c utils4.c utils5.c \
		move_push.c move_rotate.c move_swap.c move_reverse_rotate.c debug_tools.c 
#delete debug_tools.c before finishing the project
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./Include
all: makelib $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

makelib: 
	$(MAKE) -C ./libft 

%.o: %.c Makefile ./Include/libft.h ./Include/push_swap.h
	cc $(CFLAGS) -c $< -o $@ 

re: fclean all

makefclean:
	$(MAKE) -C ./libft fclean
clean:
	rm -rf $(OBJ) 

fclean: clean makefclean
	rm -rf $(NAME)

.PHONY: all re clean fclean bonus