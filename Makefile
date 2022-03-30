# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 11:21:12 by vkanate           #+#    #+#              #
#    Updated: 2022/03/29 15:23:17 by vkanate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -L/usr/local/lib -lmlx -framework OpenGL -framework Appkit


HEADER		= fractol.h
HEADER_BONUS = ./Bonus/fractol_bonus.h
NAME		= Fractol

MANDATORY_SRCS	= fractol.c mandelbrot.c julia.c init_close.c mouse.c fractol_utils.c
BONUS_SRCS		= ./Bonus/fractol_bonus.c mandelbrot.c julia.c ./Bonus/init_close_bonus.c ./Bonus/mouse_bonus.c fractol_utils.c ./Bonus/burningship.c

all: $(NAME)

bonus: fractol_bonus

norm: norminette
norm_bonus: norminette_bonus

$(NAME): $(MANDATORY_SRCS) $(HEADER)
	$(CC) $(CC_FLAGS) $(MANDATORY_SRCS) -I $(HEADER) -o $(NAME)

fractol_bonus: $(BONUS_SRCS) $(HEADER_BONUS)
	$(CC) $(CC_FLAGS) $(BONUS_SRCS) -I $(HEADER_BONUS) -o Fractol_bonus

norminette: 
	norminette -R CheckForbiddenSourceHeader $(MANDATORY_SRCS) $(HEADER)
norminette_bonus:
	norminette -R CheckForbiddenSourceHeader $(BONUS_SRCS) $(HEADER_BONUS)


clean:
		rm -f Fractol
fclean:		clean
		rm -f Fractol_bonus

re:			fclean all