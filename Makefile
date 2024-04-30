NAME = so_long
CFLAGS = -Wall -Werror -Wextra 
CC = cc
FT_PRINTF = ./ft_printf/libftprintf.a
SRC = so_long.c \
	./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c  \
	./utils/map_read.c ./utils/map_print.c ./utils/map_clean.c ./utils/utils.c \
	./utils/map_window.c ./utils/map_cheker.c ./utils/map_cheker2.c\
	./utils/player_moves1.c ./utils/floodfill.c ./utils/map_exit.c

OBJC =  $(SRC:.c=.o)

all: $(NAME)

$(OBJC) : $(SRC)

$(NAME): $(OBJC) $(FT_PRINTF)
	@-$(CC) $(OBJC) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(FT_PRINTF):
	make -C ft_printf

%.o: %.c
	@-$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@-rm -rf $(OBJC) 
	make clean -C ft_printf

fclean: clean
	@-rm -rf $(NAME)
	make fclean -C ft_printf

re: fclean 
	$(MAKE) all
	$(MAKE) clean
	

.SECONDARY:  $(OBJC)