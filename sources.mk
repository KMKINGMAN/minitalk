## SOURCES.MK ##
SRCDIR = src
## SRC FOR THE CLIENT ##
SOURCES				:= client.c client_utils.c
SOURCES_BONUS		:= client_bonus.c client_utils.c

## SRC FOR THE SERVER ##
SOURCES_SERVER		:= server.c server_utils.c client_utils.c
SOURCES_SERVER_BONUS:= server_bonus.c server_utils.c client_utils.c

# Convert to full paths
SOURCES				:= $(addprefix $(SRCDIR)/,$(SOURCES))
SOURCES_BONUS		:= $(addprefix $(SRCDIR)/,$(SOURCES_BONUS))
SOURCES_SERVER		:= $(addprefix $(SRCDIR)/,$(SOURCES_SERVER))
SOURCES_SERVER_BONUS:= $(addprefix $(SRCDIR)/,$(SOURCES_SERVER_BONUS))
