NAME = libftprintf.a


INCS = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_flags.c ft_percent.c ft_treat.c ft_hexa.c ft_pointer.c ft_uint.c ft_int.c ft_uitoa.c ft_libft.c ft_libft2.c ft_put_str.c

OBJS = ${SRC:.c=.o}

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@
$(NAME) : ${OBJS}
	        ar rc ${NAME} ${OBJS}

all     : ${NAME}

clean   :
	        rm -f *.o

fclean  : clean
	        rm -f $(NAME)

re      : fclean all
