FLAGS = -Wall -Wextra -Werror -pthread

SRCS = main.c philo_utils.c

CC = cc

NAME = philo

OBJS = $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(FLAGS) -o $(NAME)

clean	:
		rm -rf


flcean : clean
		rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJS)