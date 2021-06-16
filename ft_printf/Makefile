NAME = libft.a

HEADER   = libft.h

SRCS = ft_printf.c

#SRCSB = \

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME): $(OBJS) $(HEADER)
		ar rcs ${NAME} $?

clean:
		$(RM) $(OBJS) $(OBJSB)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

bonus:	$(OBJS) $(OBJSB)
		ar rcs ${NAME} $?

.PHONY : all clean fclean re bonus $(NAME)
