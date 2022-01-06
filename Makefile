# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:29:05 by itkimura          #+#    #+#              #
#    Updated: 2022/01/06 09:32:43 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc - Wall -Wextra -Werror
NAME = fillit
SRCS = *.c

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
