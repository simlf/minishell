##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	src/path.c 					\
			src/run_shell.c 			\
			src/check_builtin.c 		\
			src/my_cd.c 				\
			src/init_object.c 			\
			src/utils.c 				\
			src/utils2.c 				\
			src/utils3.c 				\
			src/utils4.c 				\
			src/my_str_to_word_array.c	\
			src/error.c 				\
			src/my_getnbr.c 			\
			src/my_setenv.c 			\
			src/my_unsetenv.c 			\

MAIN 	=	src/main.c 					\

OBJ     =   $(SRC:.c=.o)   	\
			$(MAIN:.c=.o)	\

CFLAGS  = -Wall -Wextra -Werror -Wshadow -I./include

CC      = gcc

RM      = rm

NAME	= mysh

all:	$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)

clean:
				$(RM) -f $(OBJ)

fclean:	clean
				$(RM) -f $(NAME)

re:		fclean all

dbg: 	CFLAGS += -g
dbg:	re

.PHONY: fclean clean re all dbg
