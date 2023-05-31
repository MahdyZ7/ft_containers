# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:00:42 by ayassin           #+#    #+#              #
#    Updated: 2023/05/31 21:11:20 by ayassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC = main.cpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -fsanitize=address # -std=c++98 # -fsanitize=address

OBJDIR = obj

HEADERS = vector.hpp Iterators.hpp ConstantIterators.hpp

_OBJS = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJDIR)/,$(_OBJS))

$(shell mkdir -p $(OBJDIR))
all : $(NAME)


$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	./$(NAME)

replit: $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEP)

fclean: clean
	rm -f $(NAME)

re : fclean all


.PHONY: clean fclean all re


# NAME = ft_containers

# SRC = main.cpp

# CC = c++

# CFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP -Iinclude -fsanitize=address

# OBJDIR = obj
# DEPDIR = dep
# # OBJSUBDIRS = Objects

# _OBJS = $(SRC:.cpp=.o)
# OBJS = $(addprefix $(OBJDIR)/,$(_OBJS))

# DEP = $(SRC:%.cpp=$(DEPDIR)/%.d)
# all : $(NAME)

# -include $(DEP)

# $(OBJDIR)/%.o: %.cpp | $(OBJDIR)
# 	if [ ! -d $(OBJDIR)]; then \
# 		mkdir -p $(OBJDIR); \
# 	fi;
# 	for dir in $(OBJSUBDIRS); do \
# 		if [ ! -d $(OBJDIR)/$$dir ]; then \
# 			mkdir -p $(OBJDIR)/$$dir; \
# 		fi; \
# 	done
# 	$(CC) $(CFLAGS) -c $^ -o $@ -MF $(DEPDIR)/$*.d

# $(NAME) : $(OBJS)
# 	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

# $(OBJ):
# 	mkdir -p $@

# clean:
# 	rm -f $(OBJS) $(DEP)

# fclean: clean
# 	rm -f $(NAME)

# re : fclean all


# .PHONY: clean fclean all re