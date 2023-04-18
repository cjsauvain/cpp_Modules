NAME = easyfind

SRCS =	main.cpp	\

OBJS_PATH = objects/

OBJS = $(SRCS:%.cpp=$(OBJS_PATH)%.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

$(OBJS_PATH)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(<:%.cpp=$(OBJS_PATH)%.o)

all: $(NAME)

objects:
	@mkdir objects

$(NAME): objects $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
