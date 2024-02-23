# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 11:49:07 by lhojoon           #+#    #+#              #
#    Updated: 2024/02/12 17:22:37 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


VERSION = 1.0.0

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./ft_putnbr_fd.c \
		./ft_putendl_fd.c \
		./ft_putstr_fd.c \
		./ft_putchar_fd.c \
		./ft_striteri.c \
		./ft_strmapi.c \
		./ft_itoa.c \
		./ft_atoi.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_split.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_strjoin.c \
		./ft_strlcpy.c \
		./ft_strlen.c \
		./ft_strncmp.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strtrim.c \
		./ft_substr.c \
		./ft_tolower.c \
		./ft_toupper.c  \
		./ft_strlcat.c
SRCB =	./ft_lstnew.c \
		./ft_lstadd_front.c \
		./ft_lstsize.c \
		./ft_lstlast.c \
		./ft_lstadd_back.c \
		./ft_lstdelone.c \
		./ft_lstclear.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./counter.c \
		./ft_printf.c \
		./implementations.c \
		./implementations2.c \
		./parser.c \
		./puthexadecimal.c \
		./utoa.c \
		./get_next_line.c \
		./get_next_line_utils.c \
		./ft_stack.c \
		./ft_abs.c \
		./ft_lstswap.c \
		./ft_lstget_idx.c \
		./ft_strjoin_many.c \
		./ft_freesplit.c
OBJS = $(SRCS:c=o)
OBJB = $(SRCB:c=o)
INCLUDES = ./
NAME = libft.a

# all: $(OBJS) $(NAME)
all: $(OBJS) $(OBJB) $(NAME)
$(NAME):
	ar rcs $(NAME) $(OBJS) $(OBJB)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean
	rm $(NAME) -f
re: fclean all
bonus: $(OBJS) $(OBJB)
	ar rcs $(NAME) $(OBJS) $(OBJB)
version:
	@echo $(VERSION)
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) -I $(INCLUDES)