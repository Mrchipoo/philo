CC = cc 
NAME = philo
GFLAGS =-Wall -Wextra -Werror #-fsanitize=thread
HEADER = philo.h
SRC = atoi.c math_utils.c init.c routine.c data.c monitor.c  string_utils.c parsing.c main.c
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER)
	$(CC) $(GFLAGS) $(OBJECT) -o $(NAME)
$(OBJECT): $(SRC)
	$(CC) $(GFLAGS) $(SRC) -c

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)
re: fclean all
