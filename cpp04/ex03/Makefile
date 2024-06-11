CC=c++
NAME = AMateria
SRCS =  main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
HEADER = AMateria.hpp Ice.hpp Cure.hpp Character.hpp ICharacter.hpp MateriaSource.hpp IMateriaSource.hpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror --std=c++98 -g

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
