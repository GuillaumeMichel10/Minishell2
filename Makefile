##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

.PHONY: all val clean fclean re

CFLAGS  += -W -Wall -Wextra -g

SRC		=	$(wildcard src/*.c)

OBJ		=	$(SRC:.c=.o)

NAME = "mysh"

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

val:
		make
		valgrind ./$(NAME) > valgrind
		cat valgrind

clean:
		make clean -C ./lib/my
		rm -f $(OBJ)

fclean:                 clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:		fclean all
