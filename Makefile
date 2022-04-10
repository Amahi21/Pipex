NAME 	=	pipex

HEADER	=	pipex.h

FLAGS 	=	-Wextra -Werror -Wall
# FLAGS =	-Wextra -Werror -Wall -fsanitize=address -fsanitize=undefined

SOURCE	=	pipex.c		src.c	\
			free.c		split.c	\
			error.c		out.c	\
			childs.c

OBJECT	=	$(SOURCE:.c=.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJECT)
			$(CC) $(OBJECT) -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJECT)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all