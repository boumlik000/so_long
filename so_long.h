#ifndef SOLONG_H
# define SOLONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <string.h>
// #include <X11/keysym.h>
#include "./get_next_line/get_next_line.h"
// #include "./printf/ft_printf.h"

#define ESC 65307
#define Q 113
#define W 119
#define S 115
#define D 100
#define A 97
#define arrow_up 65362
#define arrow_down 65364
#define arrow_left 65361
#define arrow_right 65363

typedef struct s_long
{
    void	*mlx;
    void    *window;

    void *floor;
    void *door;
    void *coin;
    void *wall;
    void *player;

    int width;
    int height;

    int count;
    int count_coins_p;

    int fd;
    char *line;
    char **map;
    int **visited;

    int player_x;
    int player_y;

    int exit_x;
    int exit_y;

    int map_y;
    int map_x;

    int exit_found;
    int collect_found ;
    int flag_player;
    int flag_coin ;
    int flag_wall;
    int flag_exit ;
    int player_height;
    int player_width;
    int total_collect;


}	t_long;

int ft_close(int keycode, void *tt , t_long *so_long);
int ft_exit(int keycode , void *tt , t_long *so_long);
int count_lines(int fd);
int fill_array(t_long *so_long);
int read_map1(t_long *so_long, char **av);
void    print_imgs(t_long *so_long, int height);
void load_images(t_long *so_long);
int count_lines(int fd);
void flood_fill(t_long *so_long, int pos_x, int pos_y);
void get_player_cord(t_long *so_long);
void map_check_borders(t_long *so_long);
void map_check_player(t_long *so_long);
void map_chek_width(t_long *so_long);
int map_check_coins(t_long *so_long);
int move_player(int keycode, t_long *so_long);
void player_coin(t_long *so_long);
void exit_cordinations(t_long *so_long);
void free_everything(t_long *so_long);
void freefun (void ** p);
#endif
