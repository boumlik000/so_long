/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:52 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/29 23:44:53 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void load_images(t_long *so_long)
{
    so_long->player = mlx_xpm_file_to_image(so_long->mlx,"textures/player.xpm",&so_long->map_width,&so_long->map_height);
    so_long->wall = mlx_xpm_file_to_image(so_long->mlx,"textures/wall.xpm",&so_long->map_width,&so_long->map_height);
    so_long->door = mlx_xpm_file_to_image(so_long->mlx,"textures/door.xpm",&so_long->map_width,&so_long->map_height);
    so_long->floor = mlx_xpm_file_to_image(so_long->mlx,"textures/bottom.xpm",&so_long->map_width,&so_long->map_height);
    so_long->coin = mlx_xpm_file_to_image(so_long->mlx,"textures/coin422.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_left0 = mlx_xpm_file_to_image(so_long->mlx,"textures/player_left.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_left1 = mlx_xpm_file_to_image(so_long->mlx,"textures/player_left1.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_right = mlx_xpm_file_to_image(so_long->mlx,"textures/player_right.xpm",&so_long->map_width,&so_long->map_height);
    so_long->door_open = mlx_xpm_file_to_image(so_long->mlx,"textures/door_open.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_down0 = mlx_xpm_file_to_image(so_long->mlx,"textures/player_down0.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_down1 = mlx_xpm_file_to_image(so_long->mlx,"textures/player_down1.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_up0 = mlx_xpm_file_to_image(so_long->mlx,"textures/player_up0.xpm",&so_long->map_width,&so_long->map_height);
    so_long->player_up1 = mlx_xpm_file_to_image(so_long->mlx,"textures/player_up1.xpm",&so_long->map_width,&so_long->map_height);
}
void print_images(t_long *so_long)
{
    load_images(so_long);
    int i = 0;
    int j = 0;
    while (i < so_long->map_y)
    {
        j = 0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            if (so_long->map[i][j] == '1')
                mlx_put_image_to_window(so_long->mlx,so_long->window,so_long->wall,j * 64,i *64);
            else if (so_long->map[i][j] == '0')
                mlx_put_image_to_window(so_long->mlx,so_long->window,so_long->floor,j * 64,i *64);
            else if (so_long->map[i][j] == 'P')
                mlx_put_image_to_window(so_long->mlx,so_long->window,so_long->player,j * 64,i *64);
            else if (so_long->map[i][j] == 'E')
                mlx_put_image_to_window(so_long->mlx,so_long->window,so_long->door,j * 64,i *64);
            else if (so_long->map[i][j] == 'C')
                mlx_put_image_to_window(so_long->mlx,so_long->window,so_long->coin,j * 64,i *64);
            j++;
        }
        i++;
    }
}
