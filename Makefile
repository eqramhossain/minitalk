# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/03/23 16:56:16 by ehossain          #+#    #+#              #
#    Updated: 2025/03/28 14:56:02 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SOURCE_SERVER = ft_server.c
SOURCE_CLIENT = ft_client.c
SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus
SOURCE_SERVER_BONUS = ft_server_bonus.c
SOURCE_CLIENT_BONUS = ft_client_bonus.c
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKE = make --no-print-directory

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(SOURCE_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SOURCE_SERVER) -L$(LIBFT_PATH) -lft
	@echo "server is complied"

$(CLIENT_NAME) : $(SOURCE_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(SOURCE_CLIENT) -L$(LIBFT_PATH) -lft
	@echo "client is complied"

$(SERVER_NAME_BONUS) : $(SOURCE_SERVER_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(SERVER_NAME_BONUS) $(SOURCE_SERVER_BONUS) -L$(LIBFT_PATH) -lft
	@echo "server is complied"

$(CLIENT_NAME_BONUS) : $(SOURCE_CLIENT_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME_BONUS) $(SOURCE_CLIENT_BONUS) -L$(LIBFT_PATH) -lft
	@echo "client is complied"

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@echo "libft obj file removed" 

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	@echo "server and client are removed"

bonus: 	$(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
