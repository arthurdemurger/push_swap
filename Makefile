# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 15:35:50 by ademurge          #+#    #+#              #
#    Updated: 2022/05/17 17:38:26 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS			= 	srcs/error.c \
					srcs/init.c \
					srcs/instructions.c \
					srcs/print_ins.c \
					srcs/push_swap.c

LIBFT			=	libft/ft_atoi.c \
					libft/ft_isdigit.c \
					libft/ft_lstadd_back.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstclear.c \
					libft/ft_lstdelone.c \
					libft/ft_lstlast.c \
					libft/ft_lstnew.c \
					libft/ft_lstsize.c \
					libft/ft_strlen.c

NAME			= push_swap

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):
				@gcc ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME}
				@echo "$(GREEN)********** Compiled. $(RESET)"

clean:
				@rm -f ${OBJS}
				@echo "$(PURPLE)********** Objects removed. $(RESET)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(LIGHTPURPLE)********** Executable removed. $(RESET)"

re:				fclean all

.PHONY:		all clean fclean re