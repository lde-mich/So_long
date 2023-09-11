# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:20:41 by lde-mich          #+#    #+#              #
#    Updated: 2023/03/03 15:46:21 by lde-mich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_mat.c  get_next_line.c  get_next_line_utils.c \
					ft_check_map.c ft_itoa.c  ft_enemy.c  ft_free_destroy.c \
					ft_print_map.c  ft_moves.c  ft_game.c  ft_check_count.c \
					ft_coins_animation.c  ft_print_moves.c \

OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLX				= -lmlx -framework OpenGL -framework AppKit

NAME			= so_long

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C mlx
				$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
				make clean -C mlx
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) libmlx.dylib
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
