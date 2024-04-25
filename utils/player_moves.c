/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:06:36 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/25 15:31:34 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_exit(t_long *so_long, int x, int y)
{
    printf("[%d]coin collected\n",so_long->total_collect);
    if (so_long->map[y][x] == 'E' && so_long->count_coins_p == so_long->total_collect)
    {
        printf("moves : %d\n", so_long->count += 1);
        printf("\nYOU WIN.\n");
        free(so_long);
        exit(0);
    }
    if (so_long->map[y][x] != 'E' || so_long->count_coins_p == so_long->total_collect)
    {
        return 1;      
    }
    return 0;
    
}

void up(t_long *so_long)
{
    int y = so_long->player_y;
    if (so_long->map[so_long->player_y - 1][so_long->player_x] != '1' && check_exit(so_long, so_long->player_x, so_long->player_y - 1))
    {
        so_long->player_y -= 1;
        printf("moves : %d\n", so_long->count += 1);
        player_coin(so_long);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, so_long->player_x * 64, y * 64);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player, so_long->player_x * 64, so_long->player_y * 64);
        if (so_long->count_coins_p == so_long->total_collect)
        {
            mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall, so_long->exit_x * 64, so_long->exit_y * 64);
        }
    }
}

void down(t_long *so_long)
{
    int y = so_long->player_y;
    if (so_long->map[so_long->player_y + 1][so_long->player_x] != '1' && check_exit(so_long, so_long->player_x, so_long->player_y + 1))
    {
        so_long->player_y += 1;
        printf("moves : %d\n", so_long->count += 1);
        player_coin(so_long);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, so_long->player_x * 64, y * 64);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player, so_long->player_x * 64, so_long->player_y * 64);
        if (so_long->count_coins_p == so_long->total_collect)
        {
            mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall, so_long->exit_x * 64, so_long->exit_y * 64);
        }
    }
}
void right(t_long *so_long)
{
    int x = so_long->player_x;
    if (so_long->map[so_long->player_y][so_long->player_x + 1] != '1' && check_exit(so_long, so_long->player_x + 1, so_long->player_y ))
    {
        so_long->player_x += 1;
        printf("moves : %d\n", so_long->count += 1);
        player_coin(so_long);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, x * 64, so_long->player_y * 64);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player, so_long->player_x * 64, so_long->player_y * 64);
        if (so_long->count_coins_p == so_long->total_collect)
        {
            mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall, so_long->exit_x * 64, so_long->exit_y * 64);
        }
    }
}

void left(t_long *so_long)
{
    int x = so_long->player_x;
     if (so_long->map[so_long->player_y][so_long->player_x - 1] != '1' && check_exit(so_long, so_long->player_x - 1, so_long->player_y))
    {
        so_long->player_x -= 1;
        printf("moves : %d\n", so_long->count += 1);
        player_coin(so_long);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, x * 64, so_long->player_y * 64);
        mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player, so_long->player_x * 64, so_long->player_y * 64);
        if (so_long->count_coins_p == so_long->total_collect)
        {
            mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall, so_long->exit_x * 64, so_long->exit_y * 64);
        }
    }
}


int move_player(int keycode, t_long *so_long)
{
    exit_cordinations(so_long);
    
    if (keycode == W || keycode == arrow_up) 
        up(so_long);
    else if (keycode == D || keycode == arrow_right) 
        right(so_long);
    else if (keycode == S || keycode == arrow_down) 
        down(so_long);
    else if (keycode == A || keycode == arrow_left) 
        left(so_long);
    return 0;
}


