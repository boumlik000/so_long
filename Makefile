NAME = so_long
CFLAGS = -Wall -Werror -Wextra
CC = cc
SRC = so_long.c
OBJC =  $(SRC:.c=.o)

all: $(NAME)

$(OBJC) : $(SRC)

$(NAME): $(OBJC)
	$(CC) $(OBJC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJC) 
fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY:  $(OBJC)