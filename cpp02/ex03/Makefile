# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:05:24 by jsauvain          #+#    #+#              #
#    Updated: 2023/03/31 19:10:36 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixedPoint

SRCS =	main.cpp	\
		Fixed.cpp	\
		Point.cpp	\
		bsp.cpp		\

OBJS_PATH = objects/

OBJS = $(SRCS:%.cpp=$(OBJS_PATH)%.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

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

c: $(NAME) clean

re: fclean all

.PHONY: all clean fclean re
