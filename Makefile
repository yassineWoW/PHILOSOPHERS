FLAGS = -Wall -Wextra -Werror

SRCS = main.c philo_utils.c parsing.c routine.c printing.c monitoring.c initialization.c

CC = cc

NAME = philo

OBJS = $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean	:
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJS)