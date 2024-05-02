NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra  -Werror 
AR = ar -rc

SRC = 	ft_printf.c\
		ft_putchar.c \
		ft_putstr.c\
		ft_putnbr.c\
		ft_strlen.c\
		ft_putnbr_base.c\
		ft_posputnbr.c\
		ft_strchr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) 
re: fclean all
