# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bifernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:13:33 by bifernan          #+#    #+#              #
#    Updated: 2023/11/24 11:32:43 by bifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -c
FLAGS = -Wall -Wextra -Werror
HEADER = libft.h
SRCS = ft_atoi.c \
	ft_isalpha.c \
	ft_itoa.c \
	ft_memmove.c \
	ft_putnbr_fd.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_isascii.c \
	ft_memchr.c \
	ft_memset.c \
	ft_putstr_fd.c \
	ft_striteri.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_isdigit.c \
	ft_memcmp.c \
	ft_putchar_fd.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_putendl_fd.c \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_substr.c 
OBJ = *.o
BONUSES = ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstnew.c \
	ft_lstlast.c \
	ft_lstadd_front.c \
	ft_lstdelone.c \
	ft_lstmap.c \
	ft_lstsize.c
 

all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(HEADER) $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ)
	@rm -f *.gch

fclean :
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@rm -f *.gch

bonus :
	@$(CC) $(FLAGS) $(HEADER) $(SRCS) $(BONUSES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

re : 
	@make fclean
	@make all
