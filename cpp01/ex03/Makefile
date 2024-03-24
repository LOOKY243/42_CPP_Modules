CC=c++
NAME = Violence
SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror --std=c++98

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re:	fclean all

.PHONY: all fclean clean re
