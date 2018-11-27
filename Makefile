# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guroux <guroux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 18:54:36 by guroux            #+#    #+#              #
#    Updated: 2018/11/27 17:06:09 by guroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o tests/main.o -c tests/main.c
	clang -o test_gnl tests/main.o get_next_line.o -I libft/includes -L libft/ -lft 
	

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all%