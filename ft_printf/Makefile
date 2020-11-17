# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 19:43:10 by yidabdes          #+#    #+#              #
#    Updated: 2020/01/30 19:22:23 by hrazani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ../libft/libft.a
PRINTF = 	ft_base_conversions.o\
			ft_helpers_3.o\
			ft_print_i.o\
			ft_print_x.o\
			ft_double_helpers.o\
			ft_ldouble_tools.o\
			ft_print_i_tools.o\
			ft_print_x_tools.o\
			ft_double_tools.o\
			ft_math_helpers.o\
			ft_print_o.o\
			ft_printf.o\
			ft_format.o\
			ft_math_tools.o\
			ft_print_p.o\
			ft_helpers.o\
			ft_print_c.o\
			ft_print_s.o\
			ft_helpers_2.o\
			ft_print_f.o\
			ft_print_u.o

PRINTF := $(addprefix src/, $(PRINTF))
FLAG = -Wall -Werror -Wextra
OBJDIR = obj
CC = gcc
INCLUDE = inc/ft_printf.h 

all : $(NAME)

$(NAME) : $(PRINTF) $(INCLUDE) $(LIBFT)
		@echo "\x1b[34m-------- PRINTF COMPILED SUCCESSFULLY --------\x1b[0m"
		@ar rc $(NAME) $(PRINTF)
		@echo "\x1b[34m-------- PRINTF ARCHIVED SUCCESSFULLY --------\x1b[0m"
$(LIBFT) :
		@make -C ../libft/
%.o : %.c
		@$(CC) $(FLAG) -c $< -o $@
clean :
		@rm -rf $(PRINTF)
		@make clean -C ../libft/
		@echo "\x1b[32m---------- CLEANED SUCCESSFULLY ----------\x1b[0m"
fclean : clean
		@rm -rf $(NAME)
re : fclean all