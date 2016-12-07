NAME = rushhour
TARBALL = brandoncheung-$(NAME).tar.gz
SRC = main.cpp coordinate.cpp vehicle.cpp boardstate.cpp node.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all:
	g++ --std=c++0x $(SRC) -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all

submit: fclean
	tar cvzf $(TARBALL) *
