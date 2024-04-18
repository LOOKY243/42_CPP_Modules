CC=c++
NAME = PhoneBook
SRCS = Contact.cpp main.cpp PhoneBook.cpp
HEADER = Contact.hpp PhoneBook.hpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -g --std=c++98

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

.PHONY: all fclean clean run run2 re
