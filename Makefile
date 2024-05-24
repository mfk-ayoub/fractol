# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 17:04:50 by ayel-mou          #+#    #+#              #
#    Updated: 2024/05/24 21:26:39 by ayel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = fractol_bonus
INCLUDE = fractol.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3



SRC = mandatory/fractol.c \
	  mandatory/mandlebrot.c \
	  utils/superlib.c \
	  mandatory/julia.c \
	  mandatory/hook_exit.c \
	  utils/key_zoom.c \
	  utils/fracol_utils.c \
	  utils/errors.c

SRC_B = bonus/fractol_bonus.c \
		mandatory/mandlebrot.c \
		bonus/superlib_bonus.c \
		mandatory/julia.c \
		bonus/hook_exit_bonus.c \
		utils/key_zoom.c \
		bonus/Burning_Ship.c \
		bonus/change_color.c \
		bonus/tricorn_set.c \
		utils/fracol_utils.c \
		utils/errors.c

OBJ = $(SRC:.c=.o) $(SRC_ALL)
OBJ_B = $(SRC_B:.c=.o) $(SRC_ALL)
LIBS = -lXext -lX11 -lmlx -lm

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)
	@echo -e "\n🚀✨ $(NAME) completed successfully! ✅✨🚀"

$(BONUS): $(OBJ_B)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_B) $(LIBS)
	@echo "✅ $(BONUS) completed successfully! ✅"

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_B)
	@echo "🧹 ...Cleaned *.o ... 🧹"

fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@echo "🧹 ...Cleaned $(NAME)!... 🧹"

re: fclean all bonus
