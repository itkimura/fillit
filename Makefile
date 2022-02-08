# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:29:05 by itkimura          #+#    #+#              #
#    Updated: 2022/02/08 11:55:05 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	fillit

OBJ_DIR		=	./objects/

INCL_HEADER =	./srcs/
SRCS_DIR	=	./srcs/
SRCS		=	main.c	validate.c	print.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

INCL_LIBFT	=	./libft
LIBFT		=	./libft/ -lft

RM			=	rm

CC = gcc
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS)-I $(INCL_HEADER) -o $@ $^ -L$(LIBFT)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INCL_HEADER) -I $(INCL_LIBFT) -o $@ -c $<

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make -C libft/ clean
	@echo "Object files has been deleted"

fclean: clean
	@make -C libft/ fclean
	@$(RM) -f $(NAME)
	@echo "Executable file has been deleted"

re: fclean all

.PHONY: all clean fclean re
