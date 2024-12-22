## SOURCES.MK ##

## SRC FOR THE CLIENT ##

SOURCES		+=           		\
		src/client.c        	\
		src/client_utils.c         	\


SOURCES_BONUS += 		 		\
		src/client_bonus.c        	\
		src/client_utils.c         	\

## SRC FOR THE SERVER ##

SOURCES_SERVER +=           		\
		src/server.c        	\
		src/server_utils.c         	\
		src/client_utils.c         	\

SOURCE_SERVER_BONUS += 		 		\
		src/server_bonus.c        	\
		src/server_utils.c         	\
		src/client_utils.c         	\
