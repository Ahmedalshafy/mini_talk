# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 09:31:12 by aalshafy          #+#    #+#              #
#    Updated: 2024/01/22 19:13:16 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
FT_PRINTF = ./ftprintf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(FT_PRINTF):
	$(MAKE) -C ./ftprintf

$(SERVER): $(FT_PRINTF) server.c
	$(CC) $(CFLAGS) $(FT_PRINTF) server.c -o $(SERVER)

$(CLIENT): $(FT_PRINTF) client.c
	$(CC) $(CFLAGS) $(FT_PRINTF) client.c -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(FT_PRINTF) server_bonus.c
	$(CC) $(CFLAGS) $(FT_PRINTF) server_bonus.c -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(FT_PRINTF) client_bonus.c
	$(CC) $(CFLAGS) $(FT_PRINTF) client_bonus.c -o $(CLIENT_BONUS)

clean:
	$(MAKE) -C ./ft_printf clean

fclean: clean
	$(MAKE) -C ./ft_printf fclean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re
