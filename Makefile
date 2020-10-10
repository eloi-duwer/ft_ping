SRC_NAME = main.c \
	send_ping.c \
	await_pongs.c \
	utils.c

NAME = ft_ping

CC = gcc

CFLAGS = -Wall -Wextra -g -I./include

SRCF = ./src/

OBJF = ./obj/

OBJS = $(addprefix $(OBJF), $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -Wall -Wextra -lm

$(OBJF)%.o: $(SRCF)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -c $(addprefix $(SRCF), $*.c)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
