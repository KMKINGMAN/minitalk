CC					:= cc
CXX					:= c++
ifeq ($(shell uname -s),Darwin)
	CC				:= gcc
	CXX				:= g++
endif

#The Target Binary Program
TARGET				:= client
TARGET_BONUS		:= client_bonus
TARGET_SERVER		:= server
TARGET_SERVER_BONUS	:= server_bonus

BUILD				:= release

include sources.mk

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR				:= src
INCDIR				:= includes
BUILDDIR			:= obj
TARGETDIR			:= bin
SRCEXT				:= c
DEPEXT				:= d
OBJEXT				:= o

OBJECTS				:= $(addprefix $(BUILDDIR)/, $(notdir $(SOURCES:.$(SRCEXT)=.$(OBJEXT))))
OBJECTS_BONUS		:= $(addprefix $(BUILDDIR)/, $(notdir $(SOURCES_BONUS:.$(SRCEXT)=.$(OBJEXT))))
OBJECTS_SERVER		:= $(addprefix $(BUILDDIR)/, $(notdir $(SOURCES_SERVER:.$(SRCEXT)=.$(OBJEXT))))
OBJECTS_SERVER_BONUS	:= $(addprefix $(BUILDDIR)/, $(notdir $(SOURCES_SERVER_BONUS:.$(SRCEXT)=.$(OBJEXT))))

#Flags, Libraries and Includes
cflags.release		:= -Wall -Werror -Wextra
cflags.valgrind		:= -Wall -Werror -Wextra -DDEBUG -ggdb
cflags.debug		:= -Wall -Werror -Wextra -DDEBUG -ggdb -fsanitize=address -fno-omit-frame-pointer
CFLAGS				:= $(cflags.$(BUILD))
CPPFLAGS			:= $(cflags.$(BUILD))

lib.release			 := -Llibft -lft -Lgc_collector -lcollect 
lib.valgrind		:= $(lib.release)
lib.debug			:= $(lib.release) -fsanitize=address -fno-omit-frame-pointer
LIB					:= $(lib.$(BUILD))

INC					:= -I$(INCDIR) -I/usr/local/include -Igc_collector -Ilibft
INCDEP				:= -I$(INCDIR) -Igc_collector -Ilibft

# Colors
C_RESET				:= \033[0m
C_PENDING			:= \033[0;36m
C_SUCCESS			:= \033[0;32m

# Multi platforms
ECHO				:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE			:= "\033[1A\033[2K\033[1A"
ERASE				:= $(ECHO) $(ES_ERASE)

GREP				:= grep --color=auto --exclude-dir=.git
NORMINETTE			:= norminette `ls`

# Default Make
all: libft $(TARGETDIR)/$(TARGET) $(TARGETDIR)/$(TARGET_SERVER)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

# Bonus rule
bonus: CFLAGS += -DBONUS
bonus: libft $(TARGETDIR)/$(TARGET_BONUS)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful with bonus! 👌 $(C_RESET)"

# Remake
re: fclean all

# Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)
	@$(RM) -f $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_SERVER) $(OBJECTS_SERVER_BONUS)
	@$(RM) -f $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))
	@make $@ -C libft
	@make $@ -C gc_collector

# Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGETDIR)
	@make $@ -C libft
	@make $@ -C gc_collector

# Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# Link
$(TARGETDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CC) $(INCDEP) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

# Link Bonus
$(TARGETDIR)/$(TARGET_BONUS): $(OBJECTS_BONUS)
	@mkdir -p $(TARGETDIR)
	$(CC) $(INCDEP) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)


# Link the server
$(TARGETDIR)/$(TARGET_SERVER): $(OBJECTS_SERVER)
	@mkdir -p $(TARGETDIR)
	$(CC) $(INCDEP) -o $(TARGETDIR)/server $^ $(LIB)

#Link the server bonus
$(TARGETDIR)/$(TARGET_SERVER_BONUS): $(OBJECTS_SERVER_BONUS)
	@mkdir -p $(TARGETDIR)
	$(CC) $(INCDEP) -o $(TARGETDIR)/server-bonus $^ $(LIB)

$(BUILDIR):
	@mkdir -p $@

# Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@$(ERASE)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

libft:
	@make -C libft
	@make -C gc_collector


norm:
	@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

# Non-File Targets
.PHONY: all re clean fclean norm bonus libft
