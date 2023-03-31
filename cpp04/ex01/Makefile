# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:05:24 by jsauvain          #+#    #+#              #
#    Updated: 2023/03/29 15:02:01 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animalIdea

SRCS =	main.cpp		\
		Animal.cpp		\
		WrongAnimal.cpp	\
		Cat.cpp			\
		WrongCat.cpp	\
		Dog.cpp			\
		Brain.cpp		\

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
