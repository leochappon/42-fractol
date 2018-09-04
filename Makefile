# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchappon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 16:42:46 by lchappon          #+#    #+#              #
#    Updated: 2018/08/19 15:30:14 by lchappon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = fractol

LIB_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./obj/

INC_NAME = fractol.h
SRC_NAME = main.c draw.c color.c info.c key.c mouse.c
OBJ_NAME = $(SRC_NAME:.c=.o)

INC = $(addprefix $(INC_PATH),$(INC_NAME))
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(INC_PATH) $(LIB_PATH)
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c -o $@ $<

$(NAME) : $(OBJ)
	make -C $(LIB_PATH)
	$(CC) -o $@ $(FRAMEWORK) -L $(LIB_PATH) -lft $^

clean :
	make -C $(LIB_PATH) clean
	/bin/rm -rf $(OBJ_PATH)

fclean : clean
	make -C $(LIB_PATH) fclean
	/bin/rm -rf $(NAME)

re : fclean all
