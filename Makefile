# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/03/23 16:56:16 by ehossain          #+#    #+#              #
#    Updated: 2025/04/03 15:51:57 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_server.c ft_client.c
OBJ = ${SRC:.c=.o}

# Executable Names
SERVER_NAME = server
CLIENT_NAME = client
SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus

# Libft
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MAKE = make --no-print-directory

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): ft_server.o $(LIBFT)
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) ft_server.o -L$(LIBFT_PATH) -lft 
	@echo "server complied"

$(CLIENT_NAME): ft_client.o $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) ft_client.o -L$(LIBFT_PATH) -lft 
	@echo "client complied"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -f ${OBJ} 
	@echo "libft & minitalk obj file removed"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	@echo "server and client are removed"

bonus: 	$(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus

# $(SERVER_NAME_BONUS) : $(SOURCE_SERVER_BONUS) $(LIBFT)
# 	@$(CC) $(CFLAGS) -o $(SERVER_NAME_BONUS) ft_server_bonus.o -L$(LIBFT_PATH) -lft
# 	@echo "Server_Bonus  is complied"
#
# $(CLIENT_NAME_BONUS) : $(SOURCE_CLIENT_BONUS) $(LIBFT)
# 	@$(CC) $(CFLAGS) -o $(CLIENT_NAME_BONUS) ft_client_bonus.o -L$(LIBFT_PATH) -lft
# 	@echo "Client_Bonous is complied"
