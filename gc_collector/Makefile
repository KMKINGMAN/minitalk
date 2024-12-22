NAME		:= libcollect.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I../libft

# Directories
SRCDIR		:= .
OBJDIR		:= obj

# Source files
SRCS		:= g_collector.c g_collector_utils.c
OBJS		:= $(SRCS:%.c=$(OBJDIR)/%.o)

# Colors
C_RESET		:= \033[0m
C_PENDING	:= \033[0;36m
C_SUCCESS	:= \033[0;32m

# Default target
all: $(NAME)

# Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile source files
$(OBJDIR)/%.o: %.c
	@echo "$(NAME)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1A\033[K"

# Create library - modified to include libft objects
$(NAME): $(OBJDIR) $(OBJS)
	@make -C ../libft
	@cp ../libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME)\t\t[$(C_SUCCESS)✅$(C_RESET)]"

# Clean object files - more specific cleaning
clean:
	@$(RM) -rf $(OBJDIR)
	@$(RM) -f $(OBJS)
	@make -C ../libft clean

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@make -C ../libft fclean

# Rebuild
re: fclean all

.PHONY: all clean fclean re
