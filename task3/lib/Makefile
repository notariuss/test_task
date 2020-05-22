NAME = lib.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
OPTIONS = -I includes
SRC_PATH = ./
SRC = $(SRC_PATH)my_memset.c \
        $(SRC_PATH)my_bzero.c \
        $(SRC_PATH)my_memcpy.c \
        $(SRC_PATH)my_memccpy.c \
        $(SRC_PATH)my_memmove.c \
        $(SRC_PATH)my_memchr.c \
		$(SRC_PATH)my_memcmp.c \
		$(SRC_PATH)my_strlen.c \
		$(SRC_PATH)my_strdup.c \
		$(SRC_PATH)my_strcpy.c \
		$(SRC_PATH)my_strncpy.c \
		$(SRC_PATH)my_strcat.c \
		$(SRC_PATH)my_strncat.c \
		$(SRC_PATH)my_strlcat.c \
		$(SRC_PATH)my_strchr.c \
		$(SRC_PATH)my_strrchr.c \
		$(SRC_PATH)my_strstr.c \
		$(SRC_PATH)my_strnstr.c \
		$(SRC_PATH)my_strcmp.c \
		$(SRC_PATH)my_strncmp.c \
		$(SRC_PATH)my_atoi.c \
		$(SRC_PATH)my_isalpha.c \
		$(SRC_PATH)my_isdigit.c \
		$(SRC_PATH)my_isalnum.c \
		$(SRC_PATH)my_isascii.c \
		$(SRC_PATH)my_isprint.c \
		$(SRC_PATH)my_toupper.c \
		$(SRC_PATH)my_tolower.c \
		$(SRC_PATH)my_memalloc.c \
		$(SRC_PATH)my_memdel.c \
		$(SRC_PATH)my_strnew.c \
		$(SRC_PATH)my_strdel.c \
		$(SRC_PATH)my_strclr.c \
		$(SRC_PATH)my_striter.c \
		$(SRC_PATH)my_striteri.c \
		$(SRC_PATH)my_strmap.c \
		$(SRC_PATH)my_strmapi.c \
		$(SRC_PATH)my_strequ.c \
		$(SRC_PATH)my_strnequ.c \
		$(SRC_PATH)my_strsub.c \
		$(SRC_PATH)my_strjoin.c \
		$(SRC_PATH)my_strtrim.c \
		$(SRC_PATH)my_strsplit.c \
		$(SRC_PATH)my_itoa.c \
		$(SRC_PATH)my_putchar.c \
		$(SRC_PATH)my_putstr.c \
		$(SRC_PATH)my_putendl.c \
		$(SRC_PATH)my_putnbr.c \
		$(SRC_PATH)my_putchar_fd.c \
		$(SRC_PATH)my_putstr_fd.c \
		$(SRC_PATH)my_putendl_fd.c \
		$(SRC_PATH)my_putnbr_fd.c \
		$(SRC_PATH)my_lstnew.c \
		$(SRC_PATH)my_lstdelone.c \
		$(SRC_PATH)my_lstdel.c \
		$(SRC_PATH)my_lstadd.c \
		$(SRC_PATH)my_lstiter.c \
		$(SRC_PATH)my_lstmap.c \
		$(SRC_PATH)my_itoa_base.c \
		$(SRC_PATH)my_nbrlen.c \
		$(SRC_PATH)my_strrev.c \
		$(SRC_PATH)my_free_tab.c \
		$(SRC_PATH)my_ptr_swap.c \
		$(SRC_PATH)mprintf.c \
		$(SRC_PATH)parse_fmt.c \
		$(SRC_PATH)print_nums.c \
		$(SRC_PATH)my_puterr.c \
		$(SRC_PATH)print_strings.c

OBJ = $(SRC:$(SRC_PATH)%.c=%.o)

./%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(OPTIONS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
