# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/03/23 16:56:16 by ehossain          #+#    #+#              #
#    Updated: 2025/04/09 10:36:47 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_putnbr.c ft_putstr.c
OBJ = ${SRC:.c=.o}

# Executable Names Mandatory
SERVER_NAME = server
CLIENT_NAME = client

# Executable Names bonus
SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MAKE = make --no-print-directory

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(OBJ) ft_server.c
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) ft_server.c $(OBJ) 
	@echo "server complied"

$(CLIENT_NAME): $(OBJ) ft_client.c
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) ft_client.c $(OBJ) 
	@echo "client complied"

$(SERVER_NAME_BONUS): $(OBJ) ft_server_bonus.c
	@$(CC) $(CFLAGS) -o $(SERVER_NAME_BONUS) ft_server_bonus.c $(OBJ) 
	@echo "server_bonus complied"

$(CLIENT_NAME_BONUS): $(OBJ) ft_client_bonus.c
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME_BONUS) ft_client_bonus.c $(OBJ) 
	@echo "client_bonus complied"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f ${OBJ} 
	@echo "Minitalk Cleaned"

fclean: clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	@echo "Minitalk Fcleaned"

bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
