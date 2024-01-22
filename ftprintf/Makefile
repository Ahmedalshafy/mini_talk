# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 09:31:12 by aalshafy          #+#    #+#              #
#    Updated: 2023/11/19 11:45:28 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFILES = \
		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c \
		ft_putadd.c ft_putunsigned.c	

OFILES = $(CFILES:.c=.o)
cc = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)
	
%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re