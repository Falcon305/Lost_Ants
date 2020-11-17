NAME  = libft.a
OBJ =	ft_atoi.o \
		ft_bzero.o \
		ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_isspace.o \
		ft_itoa.o \
		ft_lstadd.o \
		ft_lstdel.o \
		ft_lstdelone.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_lstnew.o \
		ft_memalloc.o \
		ft_memccpy.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memdel.o \
		ft_memmove.o \
		ft_memset.o \
		ft_printlst.o \
		ft_putchar.o \
		ft_putchar_fd.o \
		ft_putendl.o \
		ft_putendl_fd.o \
		ft_putnbr.o \
		ft_putnbr_fd.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strclr.o \
		ft_strcmp.o \
		ft_strcpy.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strequ.o \
		ft_strindex.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlen.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strncat.o \
		ft_strncmp.o \
		ft_strncpy.o \
		ft_strndup.o \
		ft_strnequ.o \
		ft_strnew.o \
		ft_strnstr.o \
		ft_strpos.o \
		ft_strrchr.o \
		ft_strrev.o \
		ft_strsplit.o \
		ft_strstr.o \
		ft_strsub.o \
		ft_strtrim.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_nbr_digit.o \
		get_next_line.o

INC = libft.h
GG = gcc
FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) : $(OBJ) $(INC)
		@echo "\x1b[34m-------- LIBFT COMPILED SUCCESSFULLY --------\x1b[0m"
		@ar rc $(NAME) $(OBJ)
		@echo "\x1b[34m-------- LIBFT ARCHIVED SUCCESSFULLY --------\x1b[0m"
%.o : %.c
		@$(GG) $(FLAGS) -c $< -o $@
clean :
		@rm -fr $(OBJ)
		@echo "\x1b[34m-------- LIBFT CLEANED SUCCESSFULLY --------\x1b[0m"
fclean : clean
		@rm -rf $(NAME)
re : fclean all
