# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guroux <guroux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 16:25:42 by guroux            #+#    #+#              #
#    Updated: 2018/12/03 16:37:33 by guroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

$(NAME):
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c tests/main.c
	clang -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

all: $(NAME)	