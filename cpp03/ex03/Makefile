CC=c++
NAME = DiamondTrap
SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HEADER = ClapTrap.hpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow --std=c++98

all:$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\033[1;32mCompilation Finished !\n\033[0m"

%.o : %.cpp $(HEADER)
	@$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	@rm -f $(NAME)
	@printf "\033[1;35mProgram Deleted !\n\033[0m"


clean:
	@rm -f $(OBJS)
	@printf "\033[1;35mObjects Deleted !\n\033[0m"

re: fclean all

.PHONY: all fclean clean re