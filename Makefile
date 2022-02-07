# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 09:29:05 by itkimura          #+#    #+#              #
#    Updated: 2022/02/07 23:39:35 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	fillit

OBJ_DIR		=	./objects/

INCL_HEADER =	./includes/
SRCS_DIR	=	./srcs/
SRCS		=	main.c	validate.c	print.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

INCL_LIBFT	=	./libft/includes
LIBFT		=	./libft/ -lft

RM			=	rm

CC = gcc
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ -L$(LIBFT)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INCL_HEADER) -I $(INCL_LIBFT) -o $@ -c $<

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "Object files has been deleted"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "Executable file has been deleted"

re: fclean all

lft:
	@make -C libft/ fclean && make -C libft/ && make -C libft/ clean

.PHONY: all clean fclean re lft tetrigen
