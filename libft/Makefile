# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 14:36:30 by ehossain          #+#    #+#              #
#    Updated: 2025/03/28 14:27:46 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ${shell find ./src -name "*.c"} 
NAME = libft.a
OBJECT = ${SOURCE:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT)
	@ar rcs $(NAME) $(OBJECT)
	@echo "libft complied"

%.o:%.c
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean : 
	@rm -rf $(OBJECT)

fclean : clean
	@rm -f $(NAME)
	@echo "libft.a removed"

re : fclean all

.PHONY: clean fclean re all
