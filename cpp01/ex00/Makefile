CC=c++
NAME = Zombie
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
HEADER = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror --std=c++98
LDFLAGS = 

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean run run2 re
