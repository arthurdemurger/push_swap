# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 15:35:50 by ademurge          #+#    #+#              #
#    Updated: 2022/06/02 16:17:10 by ademurge         ###   ########.fr        #
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

SRC			= 		src/complex_sort.c \
					src/error.c \
					src/free.c \
					src/init.c \
					src/instructions.c \
					src/main.c \
					src/print_ins.c \
					src/sort.c \
					src/utils.c

LIBFT			=	libft/ft_atoi.c \
					libft/ft_findindex.c \
					libft/ft_findmax.c \
					libft/ft_findmin.c \
					libft/ft_findorder.c \
					libft/ft_lst_prelast.c \
					libft/ft_isdigit.c \
					libft/ft_lstadd_back.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstclear.c \
					libft/ft_lstdelone.c \
					libft/ft_lstlast.c \
					libft/ft_lstnew.c \
					libft/ft_lstsize.c \
					libft/ft_sort_int_tab.c \
					libft/ft_split.c \
					libft/ft_strcmp.c \
					libft/ft_strdup.c \
					libft/ft_strlcpy.c \
					libft/ft_strlen.c \
					libft/ft_substr.c

BONUS_SRC		=	bonus/checker_bonus.c \
					bonus/error_bonus.c \
					bonus/free_bonus.c \
					bonus/init_bonus.c \
					bonus/instructions_bonus.c \
					bonus/print_ins_bonus.c \
					bonus/utils_bonus.c

GNL				=	gnl/get_next_line.c \
					gnl/get_next_line_utils.c

BONUS_NAME		= checker

NAME			= push_swap

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):
				@gcc ${CFLAGS} ${SRC} ${LIBFT} -o ${NAME}
				@echo "$(GREEN)********** Compiled. $(RESET)"

bonus:
				@gcc ${CFLAGS} ${BONUS_SRC} ${LIBFT} ${GNL} -o ${BONUS_NAME}
				@echo "$(YELLOW)********* Bonus compiled $(RESET)"

clean:
				@rm -f ${OBJS}
				@echo "$(PURPLE)********** Objects removed. $(RESET)"

fclean:			clean
				@rm -f $(NAME) $(BONUS_NAME)
				@echo "$(LIGHTPURPLE)********** Executable removed. $(RESET)"

re:				fclean all

.PHONY:		all clean fclean re bonus