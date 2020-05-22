NAME = ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
OPTIONS = -I includes -Ilib/includes

all: $(NAME)

$(NAME): $(SRC)
	make -C lib
	$(CC) src/*.c lib/lib.a $(FLAGS) $(OPTIONS) -o $(NAME)

clean:
	make -C lib clean
	rm -f $(OBJ)

fclean: clean
	make -C lib fclean
	rm -f $(NAME)

re: fclean $(NAME)
