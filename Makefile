# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaddox <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 11:23:26 by smaddox           #+#    #+#              #
#    Updated: 2019/07/17 23:11:48 by smaddox          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
CFILES = libft_core/ft_memset.c \
libft_core/ft_atoi.c \
libft_core/ft_bzero.c \
libft_core/ft_isalnum.c\
libft_core/ft_isalpha.c\
libft_core/ft_isascii.c\
libft_core/ft_isdigit.c\
libft_core/ft_isprint.c\
libft_core/ft_itoa.c\
libft_core/ft_memalloc.c\
libft_core/ft_memccpy.c\
libft_core/ft_memchr.c\
libft_core/ft_memcmp.c\
libft_core/ft_memcpy.c\
libft_core/ft_memdel.c\
libft_core/ft_memmove.c\
libft_core/ft_putchar.c\
libft_core/ft_putchar_fd.c\
libft_core/ft_putendl.c\
libft_core/ft_putendl_fd.c\
libft_core/ft_putnbr.c\
libft_core/ft_putnbr_fd.c\
libft_core/ft_putstr.c\
libft_core/ft_putstr_fd.c\
libft_core/ft_strcat.c\
libft_core/ft_strchr.c\
libft_core/ft_strclr.c\
libft_core/ft_strcmp.c\
libft_core/ft_strcpy.c\
libft_core/ft_strdel.c\
libft_core/ft_strdup.c\
libft_core/ft_strequ.c\
libft_core/ft_striter.c\
libft_core/ft_striteri.c\
libft_core/ft_strjoin.c\
libft_core/ft_strlcat.c\
libft_core/ft_strlen.c\
libft_core/ft_strmap.c\
libft_core/ft_strmapi.c\
libft_core/ft_strncat.c\
libft_core/ft_strncmp.c\
libft_core/ft_strncpy.c\
libft_core/ft_strnequ.c\
libft_core/ft_strnew.c\
libft_core/ft_strnstr.c\
libft_core/ft_strrchr.c\
libft_core/ft_strsplit.c\
libft_core/ft_strstr.c\
libft_core/ft_strsub.c\
libft_core/ft_strtrim.c\
libft_core/ft_tolower.c\
libft_core/ft_toupper.c\
libft_core/ft_isupper.c\
libft_core/ft_islower.c\
libft_core/ft_strrev.c\
libft_core/ft_chrswap.c\
libft_core/ft_strclen.c\
libft_core/ft_word_count.c\
libft_core/ft_lstadd.c\
libft_core/ft_lstdel.c\
libft_core/ft_lstdelone.c\
libft_core/ft_lstiter.c\
libft_core/ft_lstmap.c\
libft_core/ft_lstnew.c\
libft_core/ft_shortoa.c\
libft_core/ft_longlongtoa.c\
libft_core/ft_itoa_base.c\
libft_core/ft_unsignedlltoa.c\
ft_printf/_d2.c\
ft_printf/_X.c\
ft_printf/_c.c\
ft_printf/_d.c\
ft_printf/_f.c\
ft_printf/_o.c\
ft_printf/_p.c\
ft_printf/_s.c\
ft_printf/_u.c\
ft_printf/_x.c\
ft_printf/_pc.c\
ft_printf/ft_printf.c\
ft_printf/parse_utils.c\
ft_printf/testing_funcs.c\
ft_printf/string_ops.c\
trashcan/trashcan.c

OBJECTS = $(CFILES:%.c=%.o)
	
all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	gcc -I . -g -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
