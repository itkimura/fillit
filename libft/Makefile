# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 22:14:13 by itkimura          #+#    #+#              #
#    Updated: 2022/02/07 12:49:29 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror
NAME = libft.a
INCL= ./includes/
SRCS = *.c
OBJS = *.o

all: $(NAME)

$(NAME):
	@echo "starting creation of libft"
	@echo "Compiling ..."
	@$(CC) -I $(INCL) -c $(SRCS)
	@echo "Creation of libft"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libft created"

clean:
	@rm -f $(OBJS)
	@echo "Object files has been deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Exectuable file has been deleted"

re: fclean all

.PHONY: all clean fclean re
