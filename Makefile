# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 16:15:25 by bpodlesn          #+#    #+#              #
#    Updated: 2017/12/26 16:15:32 by bpodlesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = validation.c \
	   solver.c \
	   main.c \
       mover.c \
       swaper.c \

OBJ =	$(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

HEADER = fillit.h

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

$(NAME): $(OBJ) 
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
