# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:06:10 by codespace         #+#    #+#              #
#    Updated: 2024/11/13 14:09:05 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp
HDRS = Bureaucrat.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re