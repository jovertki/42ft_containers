NAME	= containers
SRC		= $(wildcard *.cpp)
HDR		= $(wildcard *.hpp)
OBJ		= $(patsubst %.cpp, obj/%.o,$(SRC))
DEP		= $(patsubst %.o, %.d,$(OBJ))
CFLAGS	= -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98
CC		= clang++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp $(HDR) | obj
	$(CC) $(CFLAGS) -MMD -c $< -o $@

obj:
	mkdir -p obj

clean:
	$(RM) $(DEP)
	$(RM) $(OBJ)
	rmdir obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re