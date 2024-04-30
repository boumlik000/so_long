/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/29 23:44:26 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int fill_array(t_long *so_long)
{
    int y = 0;
    int x = 0;
    so_long->visited = malloc(so_long->map_y * sizeof(int *));
    while (y < so_long->map_y)
    {
        x = 0;
        so_long->visited[y] = malloc(so_long->map_x * sizeof(int));
        while(x < so_long->map_x)
        {
            so_long->visited[y][x] = 0;
            x++;
        }
        y++;
    }
    return 0;
}
void flood_fill_parsing(t_long *so_long, int pos_x, int pos_y)
{
    if (so_long->visited[pos_x][pos_y] == 0 
    && (so_long->map[pos_x][pos_y] == 'C' || so_long->map[pos_x][pos_y] == 'P' || so_long->map[pos_x][pos_y] == '0'))
    {
        so_long->visited[pos_x][pos_y] = 1;
        if (so_long->map[pos_x][pos_y] == 'C')
            so_long->collect_found += 1;
        flood_fill_parsing(so_long, pos_x - 1, pos_y);
        flood_fill_parsing(so_long, pos_x + 1, pos_y);
        flood_fill_parsing(so_long, pos_x, pos_y - 1);
        flood_fill_parsing(so_long, pos_x, pos_y + 1);
    }
}
void flood_fill_exit(t_long *so_long, int pos_x, int pos_y)
{
    if(so_long->visited[pos_x][pos_y] == 0 && (so_long->map[pos_x][pos_y] != '1'))
    {
        so_long->visited[pos_x][pos_y] = 1;
        if (so_long->map[pos_x][pos_y] == 'E')
            so_long->exit_found += 1;
        flood_fill_exit(so_long, pos_x - 1, pos_y);
        flood_fill_exit(so_long, pos_x + 1, pos_y);
        flood_fill_exit(so_long, pos_x, pos_y - 1);
        flood_fill_exit(so_long, pos_x, pos_y + 1);
    }
}

void flood_fill(t_long *so_long)
{
    so_long->exit_found = 0;
    so_long->collect_found = 0;
    Player_cordinations(so_long);
    map_check_coins(so_long);
    //to check for coins
    fill_array(so_long);
    flood_fill_parsing(so_long,so_long->player_y, so_long->player_x);
    free_array(so_long);
    //to check for exit
    fill_array(so_long);
    flood_fill_exit(so_long,so_long->player_y, so_long->player_x);
    free_array(so_long);
    
    if (so_long->collect_found != map_check_coins(so_long) || so_long->exit_found != 1)
        (ft_printf("Error\nflood_fill unplayable map"),exit(1));
}
