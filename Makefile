# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 15:45:41 by alanghan          #+#    #+#              #
#    Updated: 2022/07/11 15:56:41 by alanghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FTNAME = ft_containers
STDNAME = std_containers
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = intramain.cpp
HEADERS = ./inc/*.hpp ./inc/utils/*.hpp

.PHONY: all clean fclean re

all: $(FTNAME) $(STDNAME)

$(FTNAME): $(SRC) $(HEADERS)
    @$(CC) $(FLAGS) $(SRC) -o $(FTNAME)
	
$(STDNAME): $(SRC) $(HEADERS)
    @$(CC) $(FLAGS) $(SRC) -o $(STDNAME) -DSTD
	
clean:
    @rm -f *.o *~
	
fclean: clean
    @rm -f $(FTNAME)
    @rm -f $(STDNAME)

re: fclean all
