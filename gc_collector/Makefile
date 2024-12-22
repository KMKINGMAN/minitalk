NAME		:= libcollect.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
BUILD		:= release

# Build type specific flags
cflags.release	:= -O2
cflags.debug	:= -g3 -DDEBUG
cflags.sanitize	:= -g3 -fsanitize=address -DDEBUG

# Directories
SRCDIR		:= .
OBJDIR		:= obj
DEPDIR		:= $(OBJDIR)/.deps

# Source files
SRCS		:= g_collector.c g_collector_utils.c
OBJS		:= $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS		:= $(SRCS:%.c=$(DEPDIR)/%.d)

# Include paths - remove libft
INCLUDES	:= -I.

# Colors and formatting
BLUE		:= \033[34m
GREEN		:= \033[32m
YELLOW		:= \033[33m
RESET		:= \033[0m
BOLD		:= \033[1m

# Default target
all: banner $(NAME)

# Pretty output
banner:
	@printf "$(BLUE)$(BOLD)Building $(NAME) [$(BUILD) mode]$(RESET)\n"

# Create directories
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

# Dependency generation
$(DEPDIR)/%.d: %.c | $(DEPDIR)
	@printf "$(YELLOW)Generating dependencies for $<$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -MM $< -MT '$(OBJDIR)/$*.o' > $@

# Compilation
$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d | $(OBJDIR)
	@printf "$(YELLOW)Compiling $<$(RESET)\n"
	@$(CC) $(CFLAGS) $(cflags.$(BUILD)) $(INCLUDES) -c $< -o $@

# Library creation - remove libft
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)$(BOLD)$(NAME) built successfully!$(RESET)\n"

# Include dependencies
-include $(DEPS)

# Debug build
debug: BUILD := debug
debug: all

# Sanitize build
sanitize: BUILD := sanitize
sanitize: all

# Clean rules - remove libft
clean:
	@rm -rf $(OBJDIR)
	@printf "$(BLUE)Cleaned object files$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(BLUE)Cleaned $(NAME)$(RESET)\n"

# Rebuild
re: fclean all

# Development tools
norm:
	@norminette $(SRCS) *.h

.PHONY: all clean fclean re debug sanitize banner norm
.SILENT: banner
