CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: client server

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re

