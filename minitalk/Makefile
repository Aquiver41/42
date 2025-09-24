CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SERVER  = server
CLIENT  = client

all: $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

clean:
	@echo "Temizlenecek .o yok"

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
.PHONY: all clean fclean re
