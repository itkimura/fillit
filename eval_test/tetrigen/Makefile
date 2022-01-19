# Non-file targets
.PHONY: all clean fclean re

# Compiler and binaries
CC=/usr/bin/gcc
RM=/bin/rm
MKDIR=/bin/mkdir

# Colors
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
NEUTRE=\e[0;m

# Program name
NAME=tetrigene

# Soruce and objects
SRCDIR=src/
SRC=$(wildcard $(SRCDIR)*.c)

OBJDIR=obj
OBJ=$(patsubst $(SRCDIR)%.c,$(OBJDIR)/%.o,$(SRC))

# Flags, include, header
CFLAGS=-Wall -Wextra -Werror

INC=include/
HEADER=$(INC)tetrigen.h

# Default make
all: $(OBJDIR) $(NAME)

$(NAME): $(HEADER) $(SRC) $(OBJ) Makefile
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@mv $(NAME) ../
	@printf "$(GREEN) ✓ Building $(NAME)\n$(NEUTRE)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(GREEN) ✓ Building $@\n$(NEUTRE)"

# Clean objects
clean:
	@if [ -e $(OBJDIR) ]; \
	then \
		$(RM) -rf $(OBJDIR); \
		printf "$(BLUE) ✗ Deletion of object files\n$(NEUTRE)"; \
	fi;

# Clean in depth
fclean: clean
		@$(RM) -f ../$(NAME)
		@printf "$(RED) ✗ Deletion of $(NAME)\n$(NEUTRE)"; \

# Remake
re: fclean all

$(OBJDIR):
	@$(MKDIR) $(OBJDIR)
	@printf "$(GREEN) ✓ Creating $(OBJDIR) dir\n$(NEUTRE)"
