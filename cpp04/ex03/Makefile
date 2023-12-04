C++ = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
NAME = Interfaces

GREEN=\033[32m
RESET=\033[0m

SOURCES = ./main.cpp ./AMateria.cpp ./Character.cpp ./Cure.cpp ./Ice.cpp ./MateriaSource.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(C++) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	@echo "$(GREEN)Linking...$(RESET)"
	@$(C++) $(OBJECTS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
