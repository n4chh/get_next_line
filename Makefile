NAME= get_next_line.

CC= clang

CFLAGS= -Wall -Wextra -Werror -std=c89 -D BUFFER_SIZE=42

SRCS=	get_next_line.c		\
		get_next_line_utils.c

SRCB=	get_next_line_bonus.c	\
		get_next_line_utils_bonus.c

OBJECTS = $(SRCS:.c=.o)
OBJECTSB = $(SRCB:.c=.o)

all: $(NAME)

bonus:
	make "OBJECTS=$(OBJECTSB)"

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -f (OBJECTS)

fclean: clean
	rm -f (OBJECTS)

re: fclean all

.PHONY: re clean fclean all bonus


