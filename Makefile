# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:29:05 by itkimura          #+#    #+#              #
#    Updated: 2022/02/06 12:44:01 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Wall -Werror -Wextra
NAME = fillit
SRCS = main.c validate.c print.c test.c libft/*.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRCS) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
