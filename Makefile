HEADER		= get_next_line.h

NAME		= get_next_line.a

SRCS 		= get_next_line.c\
			get_next_line_utils.c\

BONUS_SRCS	= get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
	

OBJS 		= $(SRCS:.c=.o)
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

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

bonus:		$(OBJS) $(BONUS_OBJS) $(HEADER)
			ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

re:			fclean all

.PHONY:		all clean fclean re bonus
