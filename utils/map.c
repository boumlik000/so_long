/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:54:49 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/19 16:34:30 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void load_images(t_long *so_long) {
    so_long->player = mlx_xpm_file_to_image(so_long->mlx, "textures/bottom.xpm", &so_long->width, &so_long->height);
    so_long->coin = mlx_xpm_file_to_image(so_long->mlx, "textures/coin42.xpm", &so_long->width, &so_long->height);
    so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "textures/wall.xpm", &so_long->width, &so_long->height);
    so_long->door = mlx_xpm_file_to_image(so_long->mlx, "textures/DOOR.xpm", &so_long->width, &so_long->height);
}

void    print_imgs(t_long *so_long, int height)
{
    
    load_images(so_long);
    
    int i = 0;
    int j = 0;
    while (i < height && so_long->map != NULL && so_long->map[i] != NULL)
    {
        j = 0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            if (so_long->map[i][j] == '1') 
                mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall, j * 64, i * 64);
            if (so_long->map[i][j] == 'C') 
                mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->coin, j * 64, i * 64);
            if (so_long->map[i][j] == 'P' || so_long->map[i][j] == '0' ) 
                mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player, j * 64, i * 64);
            if (so_long->map[i][j] == 'E') 
                mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->door, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

int read_map1(t_long *so_long, char **av)
{   
    so_long->fd = open(av[1], O_RDONLY);
    if (so_long->fd == -1)
    {
        printf("Error\nThere is no file with this name!");
        exit(0);
    }
    int lines_num = count_lines(so_long->fd);
    close(so_long->fd);
    return lines_num;
}



