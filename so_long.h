#ifndef SOLONG_H
# define SOLONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "./get_next_line/get_next_line.h"



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

    int fd;
    char *line;
    char **map;
    int **visited;

    int player_x;
    int player_y;

    int collect_found ;
    int flag_player;
    int flag_coin ;
    int flag_wall;
    int flag_exit ;



}	t_long;

int ft_close(int keycode, void *tt);
int ft_exit(int keycode , void *tt);
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

#endif
