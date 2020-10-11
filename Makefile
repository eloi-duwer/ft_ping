SRC_NAME = main.c \
	send_ping.c \
	await_pongs.c \
	utils.c

NAME = ft_ping

CC = gcc

CFLAGS = -Wall -Wextra -I./include -I./libft/include

SRCF = ./src/

OBJF = ./obj/

OBJS = $(addprefix $(OBJF), $(SRC_NAME:.c=.o))

LFT =libft/libft.a


all: $(NAME)

$(LFT):
	make -C ./libft

$(NAME): $(LFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -Wall -Wextra -lm -L./libft -lft

$(OBJF)%.o: $(SRCF)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -c $(addprefix $(SRCF), $*.c)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
