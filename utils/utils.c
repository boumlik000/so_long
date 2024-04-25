/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:11:30 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/25 15:20:15 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../so_long.h"
int ft_close(int keycode, void *tt ,t_long *so_long)
{
    (void)tt;
    if(keycode == ESC || keycode == Q)
        {
            free_everything(so_long);
            exit(0);
        }
        
    return 0;
}

int ft_exit(int keycode , void *tt , t_long *so_long)
{
    (void)tt;
    (void)keycode;
    (void)so_long;
    // free_everything(so_long);
    // mlx_destroy_image(so_long->mlx,so_long->wall);
    // mlx_destroy_image(so_long->mlx,so_long->floor);
    // mlx_destroy_image(so_long->mlx,so_long->coin);
    // mlx_destroy_image(so_long->mlx,so_long->player);
    // free_visited();
    // free_map();
    // mlx_destroy_display(so_long->mlx);
    // mlx_destroy_window(so_long->mlx, so_long->window);
    // free(so_long->mlx);
    exit(0);
    return 0;
}

int count_lines(int fd)
{
    int i = 0;
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    return i;
}
void player_coin(t_long *so_long)
{
    
    if (so_long->map[so_long->player_y][so_long->player_x] == 'C')
    {
        
        so_long->map[so_long->player_y][so_long->player_x] = '0';
        so_long->count_coins_p += 1;
        printf("c : %d\n",so_long->count_coins_p);
    } 
    
}
void exit_cordinations(t_long *so_long)
{
     int x = 0;
    int y = 0;

    while (so_long->map[y] != NULL)
    {
        x = 0;
        while(so_long->map[y][x])
        {
            if (so_long->map[y][x] == 'E')
            {
                so_long->exit_y = y;
                so_long->exit_x = x;
                return ;
            }
            x++;
        }
        y++;
    }
    return ;
}
