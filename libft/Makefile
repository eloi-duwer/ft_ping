# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:26:19 by eduwer            #+#    #+#              #
#    Updated: 2020/02/14 12:22:02 by eduwer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = append_string.c \
	context_control.c \
	main_functions.c \
	exposed_functions.c \
	double_utils.c \
	parsing/flags_parsing.c \
	parsing/get_convertion.c \
	parsing/get_modifiers.c \
	parsing/percent_convertion_process.c \
	parsing/precision_field_width.c \
	convert/convert_string.c \
	convert/convert_int.c \
	convert/convert_uint.c \
	convert/space_and_plus_flag.c \
	convert/field_width.c \
	convert/convert_octal_hexa.c \
	convert/convert_char.c \
	convert/convert_double.c

NAME = libft.a

CC = gcc

CFLAGS = -I./include -I./libft/include -Wall -Wextra -Werror

SRCF = ./srcs/ft_printf/

OBJF = ./obj/ft_printf/

OBJS = $(addprefix $(OBJF), $(SRC_NAME:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	make -f ./Makefile_libft
	ar -rc libft.a $(OBJS)
	ranlib libft.a

$(OBJF)%.o : $(SRCF)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -c $(addprefix $(SRCF), $*.c)

clean :
	rm -rf	$(OBJS)
	make -f ./Makefile_libft clean

fclean : clean
	rm -rf $(NAME)
	make -f ./Makefile_libft fclean

re : fclean all
