# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 12:21:47 by mel-hada          #+#    #+#              #
#    Updated: 2022/03/19 11:33:12 by mel-hada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= containers
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -std=c++98
RM			= rm -f
ECHO		= echo -e

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m


SRC = main.cpp

all:		$(NAME)

$(NAME):	$(SRC)
			@$(ECHO) -n "$(YELLOW)[$(NAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"

clean:

fclean:		clean
			@$(RM) $(NAME)
			@find . -name ".DS_Store" -delete
			@rm -rf checker.dSYM
			@$(ECHO) -n "$(CYAN)[containers]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"


re:			fclean  all 
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [containers]!$(DEF_COLOR)\n"

.PHONY:		all clean fclean re