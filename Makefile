NAME  = philo 
FLAGS = -Wall -Werror -Wextra  -pthread #-fsanitize=thread -g 
CC    = cc
SRS   =  utils.c utils1.c thread.c main.c init.c  lock.c unlock.c 
OBJS  = $(SRS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)
re: fclean all
