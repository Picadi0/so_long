# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 14:50:06 by maltun            #+#    #+#              #
#    Updated: 2023/05/30 18:57:37 by maltun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

BONUSSRCS = ./Bonus/ft_game.c ./Bonus/ft_game_utils.c ./Bonus/ft_game_utils2.c ./Bonus/ft_game_utils3.c ./Bonus/ft_game_utils4.c ./Bonus/ft_game_utils5.c ./Bonus/ft_game_utils6.c ./Bonus/ft_game_utils7.c ./Bonus/ft_game_utils8.c ./Bonus/ft_game_utils9.c ./Bonus/ft_game_utils10.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

SRCS = ./Mandatory/ft_game.c ./Mandatory/ft_game_utils.c ./Mandatory/ft_game_utils2.c ./Mandatory/ft_game_utils3.c ./Mandatory/ft_game_utils4.c ./Mandatory/ft_game_utils5.c ./Mandatory/ft_game_utils6.c ./Mandatory/ft_game_utils7.c ./Mandatory/ft_game_utils8.c ./Mandatory/ft_game_utils9.c ./Mandatory/ft_game_utils10.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

BONUSOBJS = $(BONUSSRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

TARGET = so_long

all: $(TARGET)

$(TARGET): $(OBJS)
	make -C minilibx 2>/dev/null
	$(CC) $(CFLAGS) $(OBJS) ./minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(TARGET)

bonus: $(BONUSOBJS)
	make -C minilibx 2>/dev/null
	$(CC) $(CFLAGS) $(BONUSOBJS) ./minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C minilibx
	rm -f $(OBJS)

fclean: clean
	rm -f $(BONUSOBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re