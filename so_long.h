#ifndef SOLONG_H
# define SOLONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include "./get_next_line.h"

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
}	t_long;

#endif
