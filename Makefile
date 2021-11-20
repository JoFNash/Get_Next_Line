HiADER		= get_next_line.h

NAME		= get_next_line.a

SRCS 		= get_next_line.c\
			get_next_line_utils.c\


OBJS 		= $(SRCS:.c=.o)

CC 			= gcc

RM 			= rm -rf

CFLAGS 		= -Wall -Wextra -Werror

%.o : %.c	$(HEADER) 
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS) $(HEADER)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
