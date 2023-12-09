C++ = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = intern

GREEN=\033[32m
RESET=\033[0m

SOURCES = ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./ShrubberyCreationForm.cpp \
		./RobotomyRequestForm.cpp ./PresidentialPardonForm.cpp ./Intern.cpp

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
