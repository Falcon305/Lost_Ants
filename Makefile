# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrazani <hrazani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/30 14:42:02 by yidabdes          #+#    #+#              #
#    Updated: 2020/02/16 22:39:37 by hrazani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
LIBFT_PRINTF = ft_printf/libftprintf.a
PARSER =	ft_checker_tools1.o\
			ft_checker_tools2.o\
			ft_fill_data.o\
			ft_get_data.o\
			ft_lists_tools.o\
			ft_parsing_data.o\
			ft_free_struct_pars.o\
			ft_search_tools.o\

ALGORITHM = algo.o\
			algo_tools.o\
			backtrack.o\
			bfs.o\
			group.o\
			main.o\
			path.o\
			queue.o\
			score.o\
			algo_tools2.o\
			move_tools.o\
			move_ants.o\
			special_case.o\
			algo_free.o\
			stack.o

PARSER := $(addprefix src/parser/, $(PARSER))
ALGORITHM := $(addprefix src/algorithm/, $(ALGORITHM))
FLAG = -Wall -Werror -Wextra 
OBJDIR = obj
CC = gcc
NAME = lem-in
INCLUDE = includes/lem_in.h

all : $(NAME)

$(NAME) : $(PARSER) $(ALGORITHM) $(INCLUDE) $(LIBFT) $(LIBFT_PRINTF)
		@$(CC) $(FLAG) $(PARSER) $(ALGORITHM) $(LIBFT) $(LIBFT_PRINTF) -o $(NAME)
		@echo "\x1b[32m---------- COMPILED SUCCESSFULLY ----------\x1b[0m"
$(LIBFT) :
		@make -C libft/
$(LIBFT_PRINTF) :
		@make -C ft_printf/
%.o : %.c
		@$(CC) $(FLAG) -c $< -o $@
clean :
		@rm -rf $(PARSER) $(ALGORITHM)
		@make clean -C libft/
		@make clean -C ft_printf/
		@echo "\x1b[32m---------- CLEANED SUCCESSFULLY ----------\x1b[0m"
fclean : clean
		@make fclean -C libft/
		@make fclean -C ft_printf/
		@rm -rf $(NAME)
re : fclean all

