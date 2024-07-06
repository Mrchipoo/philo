CC = cc 
NAME = philo
CFLAGS = -Wall -Wextra -Werror -g3
HEADER = philo.h
SRC = main.c
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER)
	$(CC) $(GFLAGS) $(OBJECT) -g3 -o $(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)
re: fclean all
