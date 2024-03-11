# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 12:54:48 by mchamma           #+#    #+#              #
#    Updated: 2023/08/22 16:31:30 by mchamma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
FLAGS = -Werror -Wextra -Wall

SRC = ft_printf.c ft_printf_utils.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	ar -rcs $(NAME) $(SRC_OBJ)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus: all

clean:
	rm -f *.o

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all bonus clean fclean re

