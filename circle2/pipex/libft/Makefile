# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 17:59:33 by fbaras            #+#    #+#              #
#    Updated: 2025/07/30 17:59:33 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC =   ft_isdigit.c   ft_memset.c      ft_striteri.c  ft_strrchr.c \
		ft_isprint.c   ft_putchar_fd.c  ft_strjoin.c   ft_strtrim.c \
		ft_atoi.c      ft_putendl_fd.c  ft_strlcat.c   ft_substr.c \
		ft_bzero.c     ft_putnbr_fd.c   ft_strlcpy.c   ft_tolower.c \
		ft_calloc.c    ft_memchr.c      ft_putstr_fd.c   ft_strlen.c    ft_toupper.c \
		ft_isalnum.c   ft_memcmp.c      ft_split.c       ft_strmapi.c \
		ft_isalpha.c   ft_memcpy.c      ft_strchr.c      ft_strncmp.c \
		ft_isascii.c   ft_memmove.c     ft_strdup.c      ft_strnstr.c ft_itoa.c

SRC_BONUS = ft_lstlast.c ft_lstmap.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c ft_lstsize.c
	
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:$(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
