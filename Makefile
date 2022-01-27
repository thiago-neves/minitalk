SERVER_NAME		=	server
SERVER_SRCS		=	./src/server.c ./src/exit.c
SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)

CLIENT_NAME		=	client
CLIENT_SRCS		=	./src/client.c ./src/utils.c ./src/exit.c
CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I includes

PRINTF			=	libftprintf.a
PRINTF_DIR		=	ft_printf/

all				:	$(PRINTF) server client

$(PRINTF)		:
					make -C $(PRINTF_DIR)

server			:	$(SERVER_OBJS)
					@$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME) $(PRINTF_DIR)/$(PRINTF)

client			:	$(CLIENT_OBJS)
					@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME) $(PRINTF_DIR)/$(PRINTF)

clean			:
					@rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
					@make -C $(PRINTF_DIR) clean

fclean			:	clean
					@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
					@make -C $(PRINTF_DIR) fclean

re				:	fclean all