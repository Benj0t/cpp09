SRCS	=	main.cpp	PmergeMe.cpp
OBJS	=	$(SRCS:.cpp=.o)
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	PmergeMe
CC		=	c++

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
all:	${NAME}
${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean:
			rm -f ${OBJS}
fclean:		clean
			rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re