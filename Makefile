NAME		=	libfstring.a

CFLAGS		=	-Wall -Wextra -Werror
DEBUG_FLAGS	=	-Wall -Wextra -ggdb3

INCLUDE		=	./

SRCS		=	get_nbr.c get_nbr2.c get_nbr3.c get_nbr4.c

OBJS		=	${SRCS:.c=.o}
DEBUG_OBJS	=	${OBJS:.o=_debug.o}

all: 		$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

debug:		$(DEBUG_OBJS)
	ar -rc $(NAME)_debug $(DEBUG_OBJS)
	ranlib $(NAME)_debug

%.o:		%.c
	cc -I$(INCLUDE) $(CFLAGS) -c $< -o $@

%_debug.o:	%.c
	cc -I$(INCLUDE) $(DEBUG_FLAGS) -c $< -o $@

mclean: all clean
dclean: debug clean

clean:
	rm -f $(OBJS) $(DEBUG_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME)_debug

re:		fclean all

.PHONY:	all re clean fclean debug mclean dclean
