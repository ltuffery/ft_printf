# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 19:01:38 by ltuffery          #+#    #+#              #
#    Updated: 2022/11/15 12:58:09 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a

CC		:= clang

CFLAGS	:= -Wall -Wextra -Werror

#=============================================#

SRCS	:= src/ft_printf.c \
	src/ft_printf_utils.c

OBJS	:= $(SRCS:.c=.o)

#=============================================#

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	mv libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
	@make fclean -C libft

%.o: %.c
	@echo "===== Compile Files ====="
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

#============================================#

run:
	@echo "Test"
	@make fclean
	@make
	@gcc tests/main.c libftprintf.a

run2:
	@echo "Valgrind Test"
	@gcc main.c libftprintf.a -o test
	@valgrind ./test


.PHONY: clean fclean all re libft
