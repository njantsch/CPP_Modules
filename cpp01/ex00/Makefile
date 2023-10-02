C++ = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = zombies

SOURCES = ./main.cpp ./newZombie.cpp ./randomChump.cpp ./Zombie.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@$(C++) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
