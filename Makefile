##
## EPITECH PROJECT, 2022
## maths
## File description:
## Makefile
##

NAME		=	201yams

NAMET		=	unit_tests

CPPFLAGS	=	-iquote include/

CC 			=	g++

CXXFLAGS	=	-std=c++17 -Wall -Wextra

LDLIBS 		= 	--coverage -lcriterion

SDIR		=	sources

TDIR = tests

SRC			=	$(SDIR)/error.cpp	\
				$(SDIR)/yams.cpp

SRCT		=	$(TDIR)/errorTests.cpp	\
				$(TDIR)/yamsTests.cpp	\

MAIN		=	$(SDIR)/main.cpp

OBJ			=	$(SRC:.cpp=.o) \
				$(MAIN:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o  $(NAME) $(OBJ) $(CXXFLAGS) $(SFML_FLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) vgcore.*
	$(RM) *.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMET)

re: fclean $(NAME)

debug:	CXXFLAGS += -g3
debug: ${OBJ}
	${CC} -o $(NAME) $(OBJ) $(CXXFLAGS) $(SFML_FLAGS) $(LDFLAGS)


tests_run: CXXFLAGS += --coverage
tests_run:
	$(CXX) -o $(NAMET) $(CXXFLAGS) $(SRC) $(SRCT) $(CPPFLAGS) $(LDLIBS) && ./$(NAMET)

coverage:
	gcovr --exclude tests

branches:
	gcovr --branches --exclude tests

.PHONY: all clean fclean re debug tests_run coverage branches