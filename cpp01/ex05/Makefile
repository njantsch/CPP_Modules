C++ = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = harl

SOURCES = ./main.cpp ./Harl.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@$(C++) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
