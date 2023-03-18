# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:00:42 by ayassin           #+#    #+#              #
#    Updated: 2023/03/18 18:23:37 by ayassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC = main.cpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP -I #-fsanitize=address

OBJSUBDIRS = Objects

OBJS = $(SRC:.cpp=.o)
# _OBJS = $(SRC:.cpp=.o)
# OBJS = $(addprefix $(OBJDIR)/,$(_OBJS))

DEP := $(OBJS:.o=.d)

all : $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $^ 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEP)

fclean: clean
	rm -f $(NAME)

re : fclean all

-include $(DEP)

.PHONY: clean fclean all re