# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 09:31:12 by aalshafy          #+#    #+#              #
#    Updated: 2024/01/20 16:05:05 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -o $(CLIENT) client.c
	$(CC) $(CFLAGS) -o $(SERVER) server.c

clean:
	$(MAKE) clean -C 

fclean: 
	$(MAKE) fclean -C 
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re