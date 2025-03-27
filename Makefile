# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/03/23 16:56:16 by ehossain          #+#    #+#              #
#    Updated: 2025/03/27 14:55:19 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SOURCE_SERVER = ft_server.c
SOURCE_CLIENT = ft_client.c
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus
SOURCE_BONUS_SERVER = ft_server_bonus.c
SOURCE_BONUS_CLIENT = ft_client_bonus.c
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(SOURCE_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SOURCE_SERVER) -L$(LIBFT_PATH) -lft

$(CLIENT_NAME) : $(SOURCE_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(SOURCE_CLIENT) -L$(LIBFT_PATH) -lft

clean:

fclean:

re: clean fclean

.PHONY: clean fclean re all
