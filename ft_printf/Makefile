# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 20:43:03 by tneves            #+#    #+#              #
#    Updated: 2021/02/09 20:43:04 by tneves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c src/print_variable.c src/set_parameters.c \
src/print_c.c src/print_d_u.c src/print_p.c src/print_pcnt.c src/ft_utoa.c \
src/print_s.c src/print_x.c src/print_in_screen.c

OBJ = ft_printf.o print_variable.o set_parameters.o \
print_c.o print_d_u.o print_p.o print_pcnt.o ft_utoa.o \
print_s.o print_x.o print_in_screen.o

$(NAME): ft_printf.h $(SRC)
	@$(MAKE) bonus -C ./libft
	@cp libft/libft.a $(NAME)
	@gcc -Wall -Wextra -Werror -c $(SRC) -I printf.h -g
	@ar -rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean test
