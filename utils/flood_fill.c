/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:43:24 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/21 13:45:44 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int map_check_coins(t_long *so_long)
{
    int i = 0;
    int j =0;
    int flag = 0;
    while (so_long ->map[i] != NULL)
    {
        j= 0;
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            if (so_long->map[i][j]  == 'C')
                flag += 1 ;
            j++;
        }
        i++;
    }
    return flag;
}
int fill_array(t_long *so_long)
{
    int i = 0;
    int j = 0;
    so_long->visited = malloc(so_long->height * sizeof(int *));
    while (i < so_long->height)
    {
        j = 0;
        so_long->visited[i] = malloc(so_long->width * sizeof(int));
        while(j < so_long->width)
        {
            so_long->visited[i][j] = 0;
            j++;
        }
        i++;
    }
    return 0;
}
void flood_fill(t_long *so_long, int pos_x, int pos_y)
{
    if (pos_x > 0 && pos_x < so_long->height && pos_y > 0 && pos_y < so_long->width  && so_long->visited[pos_x][pos_y] == 0 && (so_long->map[pos_x][pos_y] == '0' || so_long->map[pos_x][pos_y] == 'P' || so_long->map[pos_x][pos_y] == 'C'))
    {
        so_long->visited[pos_x][pos_y] = 1;
        if (so_long->map[pos_x][pos_y] == 'C')
            so_long->collect_found += 1;
        flood_fill(so_long, pos_x - 1, pos_y);
        flood_fill(so_long, pos_x + 1, pos_y);
        flood_fill(so_long, pos_x, pos_y - 1);
        flood_fill(so_long, pos_x, pos_y + 1);
    }
}

void get_player_cord(t_long *so_long)
{
    int x = 0;
    int y = 0;

    while (so_long->map[y] != NULL)
    {
        x = 0;
        while(so_long->map[y][x])
        {
            if (so_long->map[y][x] == 'P')
            {
                so_long->player_y = y;
                so_long->player_x = x;
                return ;
            }
            x++;
        }
        y++;
    }
    return ;
}